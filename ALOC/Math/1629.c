// modular 연산 활용!
// 분할을 이용한 거듭제곱
#include    <stdio.h>

long long	mul_recur(long long a, long long b, long long c)
{
	a %= c;
	if (b == 1)
		return (a);
	if (b % 2 == 0)
		return (mul_recur(a * a, b / 2, c) % c);
	else
		return (a * mul_recur(a * a, b / 2, c) % c);
}

long long	mul_iter(long long a, long long b, long long c)
{
	long long	result;

	result = 1;
	a %= c;
	while (b != 0)
	{
		if (b % 2 != 0)
			result = result * a % c;
		a = a * a % c;
		b /= 2;
	}
	return (result);
}

int main(void)
{
    long long a;
    long long b;
    long long c;

    scanf("%lld %lld %lld", &a, &b, &c);    
    printf("%lld\n", mul_recur(a, b, c));
	// printf("%lld\n", mul_iter(a, b, c));
    return (0);
}
