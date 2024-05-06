#include	<stdio.h>

int	main(void)
{
	long	n;

	scanf("%ld", &n);
	printf("%ld\n", (n - 1) + (n - 1) * (n - 2));
	for (long i = 2; i <= n; i++)
		printf("1 %ld\n", i);
	return (0);
}
