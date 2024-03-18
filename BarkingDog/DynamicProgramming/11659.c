#include	<stdio.h>

int	main(void)
{
	int	n;
	int	m;
	int	num[100001];
	int	sum[100001];
	int	i;
	int	j;

	scanf("%d %d", &n, &m);
	sum[0] = 0;
	for (int idx = 1; idx <= n; idx++)
	{
		scanf("%d", &num[idx]);
		sum[idx] = sum[idx - 1] + num[idx];
	}
	for (int idx = 0; idx < m; idx++)
	{
		scanf("%d %d", &i, &j);
		printf("%d\n", sum[j] - sum[i - 1]);
	}
	return (0);
}
