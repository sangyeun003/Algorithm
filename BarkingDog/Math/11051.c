#include	<stdio.h>

int	factorial_with_modular(int n, int m)
{
	int	result;

	result = 1;
	for (int i = 2; i <= n; i++)
		result = (result * (i % m)) % m;
	return (result);
}

int	main(void)
{
	int	n;
	int	k;

	scanf("%d %d", &n, &k);
	printf("%d\n", factorial_with_modular(n, k) );
	return (0);
}
