#include	<stdio.h>

int	main(void)
{
	int	n;
	int	d[1001];

	scanf("%d", &n);
	d[0] = 0;
	d[1] = 1;
	d[2] = 2;
	for (int i = 3; i <= n; i++)
		d[i] = (d[i - 1] + d[i - 2]) % 10007;
	printf("%d\n", d[n]);
	return (0);
}
