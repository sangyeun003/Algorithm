#include	<stdio.h>

int	gcd(int a, int b)
{
	if (a % b == 0)
		return (b);
	return (gcd(b, a % b));
}

int	lcm(int a, int b)
{
	return (a / gcd(a, b) * b);
}

int	main(void)
{
	int	t;
	int	m;
	int	n;
	int	x;
	int	y;
	int	l;

	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d %d %d %d", &m, &n, &x, &y);
		if (x == m)
			x = 0;
		if (y == n)
			y = 0;
		l = lcm(m, n);
		for (int j = x; j <= l; j += m)
		{
			if (j != 0 && j % n == y)
			{
				printf("%d\n", j);
				break ;
			}
			if (j + m > l)
				printf("-1\n");
		}
	}
	return (0);
}
