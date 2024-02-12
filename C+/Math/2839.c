#include    <stdio.h>

#define BIG 5
#define SMALL   3

int d[5001];

int min(int a, int b)
{
    return (a < b ? a : b);
}

int main(void)
{
    int n;

    scanf("%d", &n);
    d[SMALL] = 1;
    d[4] = -1;
    d[BIG] = 1;
    d[6] = 2;
    d[7] = -1;
    for (int i = 8; i < n + 1; i++)
    {
        if (i % BIG == 0)
            d[i] = i / BIG;
        else
        {
            if (d[i - SMALL] != -1 && d[i - BIG] != -1)
                d[i] = min(d[i - SMALL], d[i - BIG]) + 1;
            else if (d[i - SMALL] != -1)
                d[i] = d[i - SMALL] + 1;
            else if (d[i - BIG] != -1)
                d[i] = d[i - BIG] + 1;
        }
    }
    printf("%d\n", d[n]);
    return (0);
}