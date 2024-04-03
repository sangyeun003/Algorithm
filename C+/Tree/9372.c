// 항상 연결 그래프!
#include	<stdio.h>

int	main(void)
{
	int	t;
	int	n;
	int	m;
	int	plane[10000][2];

	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d %d", &n, &m);
		for (int j = 0; j < m; j++)
			scanf("%d %d", &plane[j][0], &plane[j][1]);
		printf("%d\n", n - 1);
	}
	return (0);
}
