#include	<stdio.h>

int	min(int a, int b)
{
	return (a > b ? b : a);
}

int	main(void)
{
	int	n;
	int	cost[1001][3];
	int	total[1001][3];

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
	
	// 초기값 정하기
	total[1][0] = cost[1][0];
	total[1][1] = cost[1][1];
	total[1][2] = cost[1][2];

	// 점화식
	// total[i][j] = i번째 집을 j색으로 칠할 때, i번째 집까지 칠하는 비용의 최소값(j = 0(red), 1(green), 2(blue))
	// total[i][0] = min(total[i - 1][1], total[i - 1][2]) + cost[i][0]
	// total[i][1] = min(total[i - 1][0], total[i - 1][2]) + cost[i][1]
	// total[i][2] = min(total[i - 1][0], total[i - 1][1]) + cost[i][2]
	for (int i = 2; i <= n; i++)
	{
		total[i][0] = min(total[i - 1][1], total[i - 1][2]) + cost[i][0];
		total[i][1] = min(total[i - 1][0], total[i - 1][2]) + cost[i][1];
		total[i][2] = min(total[i - 1][0], total[i - 1][1]) + cost[i][2];
	}
	printf("%d\n", min(total[n][0], min(total[n][1], total[n][2])));
	return (0);
}
