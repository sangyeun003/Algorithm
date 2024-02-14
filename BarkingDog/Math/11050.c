#include	<stdio.h>

int	factorial(int n)
{
	int	result;

	result = 1;
	for (int i = 1; i <= n; i++)
		result *= i;
	return (result);
}

int	main(void)
{
	int	n;
	int	k;

	scanf("%d %d", &n, &k);
	printf("%d\n", factorial(n) / factorial(n - k) / factorial(k));
	return (0);
}
