#include	<stdio.h>

int	is_available(int broken[], int n)
{
	if (n == 0)
		return (broken[n] == 0);
	while (n != 0)
	{
		if (broken[n % 10] == 1)
			return (0);
		n /= 10;
	}
	return (1);
}

int	digit(int n)	// 자릿수 계산(숫자 눌러서 이동할 때 숫자 눌러야 하는 횟수)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	abs(int n)
{
	return (n >= 0 ? n : (-1) * n);
}

int	min(int a, int b)
{
	return (a < b ? a : b);
}

int	main(void)
{
	int	n;
	int	m;
	int	broken[10] = {0};
	int	temp;
	int	ans;

	scanf("%d", &n);
	scanf("%d", &m);
	if (m != 0)
	{
		for (int i = 0; i < m; i++)
		{
			scanf("%d", &temp);
			broken[temp] = 1;
		}
	}
	ans = abs(n - 100);	// +/-로 이동할 때의 횟수
	if (n != 100)
	{
		for (int i = 0; i <= 999999; i++)
		{
			if (is_available(broken, i))
			{
				ans = min(ans, digit(i) + abs(i - n));
			}
		}
	}
	printf("%d\n", ans);
	return (0);
}
