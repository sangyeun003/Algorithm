#include    <stdio.h>

int remain[10000001] = {10000001};   // index: 앞에 남은 사람 수, value: 앞 사람이 index가 될 때까지 걸린 시간

int main(void)
{
    int n;
    int a;
    int b;

    scanf("%d %d %d", &n, &a, &b);
    if (n >= a || n >= b)
        printf("%d\n", n);
    else
    {
        for (int i = n; i > 0; i--)
        {

        }
    }

    return (0);
}
https://cochin-man.tistory.com/50