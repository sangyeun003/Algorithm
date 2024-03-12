#include	<stdio.h>

int	is_hannum(int n)
{
	int	diff1;
	int	diff2;

	if (n / 100 == 0)	// 2자리 이하 수는 무조건 한수
		return (1);
	if (n == 1000)
		return (0);
	// 세 자리 수
	diff1 = n / 100 - n / 10 % 10; // 첫 번째 자리 - 두 번째 자리
	diff2 = n / 10 % 10 - n % 10; // 두 번째 자리 - 세 번째 자리
	if (diff1 == diff2)
		return (1);
	else
		return (0);
}

int	main(void)
{
	int	n;
	int	count;

	scanf("%d", &n);
	count = 0;
	for (int i = 1; i <= n; i++)
	{
		if (is_hannum(i) == 1)
			count++;
	}
	printf("%d\n", count);
	return (0);
}
