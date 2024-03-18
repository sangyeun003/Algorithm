#include	<stdio.h>

int	main(void)
{
	int	n;
	int	dist[1000001];
	int	pre[1000001];

	scanf("%d", &n);
	dist[0] = 0;
	dist[1] = 0;
	pre[0] = 0;
	pre[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		dist[i] = dist[i - 1] + 1;
		pre[i] = i - 1;
		if (i % 3 == 0 && dist[i / 3] + 1 < dist[i])
		{
			dist[i] = dist[i / 3] + 1;
			pre[i] = i / 3;
		}
		if (i % 2 == 0 && dist[i / 2] + 1 < dist[i])
		{
			dist[i] = dist[i / 2] + 1;
			pre[i] = i / 2;
		}
	}
	printf("%d\n", dist[n]);
	while (n != 0)
	{
		printf("%d ", n);
		n = pre[n];
	}
	return (0);
}