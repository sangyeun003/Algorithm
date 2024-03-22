#include	<stdio.h>

#define N	1000

int	cost[N + 1][3];

// 테이블 정의
// total[i][0] = i번째 집까지 색칠할 때 최소 비용. 단 i번째 집은 Red
// total[i][1] = i번째 집까지 색칠할 때 최소 비용. 단 i번째 집은 Green
// total[i][2] = i번째 집까지 색칠할 때 최소 비용. 단 i번째 집은 Blue
int	total[N + 1][3];

int	min(int a, int b)
{
	return (a < b ? a : b);
}

int	main(void)
{
	int	n;

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
	total[1][0] = cost[1][0];
	total[1][1] = cost[1][1];
	total[1][2] = cost[1][2];
	// 점화식
	// total[i][0] = min(total[i - 1][1], total[i - 1][2]) + cost[i][0]
	// total[i][1] = min(total[i - 1][0], total[i - 1][2]) + cost[i][1]
	// total[i][2] = min(total[i - 1][0], total[i - 1][1]) + cost[i][2]
	for (int i = 2; i <= N; i++)
	{
		total[i][0] = min(total[i - 1][1], total[i - 1][2]) + cost[i][0];
		total[i][1] = min(total[i - 1][0], total[i - 1][2]) + cost[i][1];
		total[i][2] = min(total[i - 1][0], total[i - 1][1]) + cost[i][2];
	}
	printf("%d\n", min(total[N][0], min(total[N][1], total[N][2])));
	return (0);
}
