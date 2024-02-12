#include    <stdio.h>

int d[11];

int main(void)
{
    int t;
    int n;

    scanf("%d", &t);
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    for (int i = 4; i < 11; i++)
            d[i] = d[i - 3] + d[i - 2] + d[i - 1];
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &n);
        printf("%d\n", d[n]);
    }
    return (0);
}
