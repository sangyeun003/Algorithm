#include    <stdio.h>

int num[1000001];

int main(void)
{
    int m;
    int n;
    int end;

    scanf("%d", &m);
    scanf("%d", &n);
    num[1] = -1;
    for (int i = 1; i * i < n; i++)
        end = i;
    for (int i = 2; i <= end; i++)
    {
        if (num[i] != -1)
        {
            for (int j = 2; i * j <= n; j++)
                num[i * j] = -1;
        }
    }
    for (int i = m; i <= n; i++)
    {
        if (num[i] != -1)
            printf("%d\n", i);
    }
    return (0);
}