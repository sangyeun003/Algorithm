// modular 연산 활용!
#include    <stdio.h>

int main(void)
{
    long a;
    long b;
    long c;
    long result;

    scanf("%ld %ld %ld", &a, &b, &c);
    result = 1;
    a %= c;
    for (int i = 0; i < b; i++)
        result = result * a % c;
    printf("%ld\n", result);
    return (0);
}
