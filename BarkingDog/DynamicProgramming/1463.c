#include    <stdio.h>

int dist[1000001];

int min(int a, int b)
{
    return (a < b ? a : b);
}

int main(void)
{
    int n;

    scanf("%d", &n);    
    for (int i = 2; i < n + 1; i++)
    {
        dist[i] = 1 + dist[i - 1];
        if (i % 3 == 0)
            dist[i] = min(dist[i], 1 + dist[i / 3]);
        // else if로 하면 안됨
        // 2와 3의 공배수의 경우 문제될 수 있음
        if (i % 2 == 0)
            dist[i] = min(dist[i], 1 + dist[i / 2]);
    }
    printf("%d\n", dist[n]);
    return (0);
}
