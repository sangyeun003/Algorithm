#include	<stdio.h>

int	make_dn(int n)
{
	if (n < 10)
		return (n);
	return (make_dn(n / 10) + n % 10);
}

int	main(void)
{
	int	arr[10001] = {0};
	int	index;

	for (int i = 1; i <= 10000; i++)
	{
		index = i + make_dn(i);
		if (index <= 10000)
			arr[i + make_dn(i)] = 1;
	}
	for (int i = 1; i <= 10000; i++)
	{
		if (arr[i] == 0)
			printf("%d\n", i);
	}
	return (0);
}
