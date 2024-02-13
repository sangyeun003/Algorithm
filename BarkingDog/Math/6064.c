// 연립합동방정식
// M으로 나눴을 때 나머지가 x && N으로 나눴을 때 나머지가 y인 수 찾기
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
	// gcd를 먼저 나눈 이유는 a * b의 overflow를 방지하기 위함.
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
