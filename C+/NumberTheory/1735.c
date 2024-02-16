#include	<stdio.h>

int	gcd(int a, int b)
{
	if (b == 0)
		return (a);
	return (gcd(b, a % b));
}

int	lcm(int a, int b)
{
	return (a / gcd(a, b) * b);
}

int	main(void)
{
	int	a1;
	int	a2;
	int	b1;
	int	b2;
	int	l;
	int	son;
	int	mom;
	int	g;

	scanf("%d %d", &a1, &b1);
	scanf("%d %d", &a2, &b2);
	l = lcm(b1, b2);
	son = l / b1 * a1 + l / b2 * a2;
	mom = l;
	g = gcd(son, mom);
	if (g != 1)
	{
		son /= g;
		mom /= g;
	}
	printf("%d %d\n", son, mom);
	return (0);
}
