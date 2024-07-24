#include	<stdio.h>

int	check_triple_6(int n)
{
	int	cnt;

	cnt = 0;
	while (n != 0)
	{
		if (n % 10 == 6)
			cnt++;
		else
			cnt = 0;
		if (cnt == 3)
			return (1);
		n /= 10;
	}
	return (0);
}

int	main(void)
{
	int	n;
	int	cnt;

	scanf("%d", &n);
	cnt = 0;
	for (int i = 1; ; i++)
	{
		if (check_triple_6(i) == 1)
			cnt++;
		if (cnt == n)
		{
			printf("%d\n", i);
			break ;
		}
	}
	return (0);
}
