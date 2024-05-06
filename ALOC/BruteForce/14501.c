// 각 날을 선택할지 말지
// brute force -> worst case 시간복잡도 = 2^15
// DP -> dp[x] = max(i일에 상담할 경우, i일이 상담하지 않을 경우)
// Top-Down
#include	<stdio.h>

int	max(int a, int b)
{
	return (a > b ? a : b);
}

int	main(void)
{
	int	n;
	int	table[16][2];	// [0]: time, [1]: profit
	int	max_profit[16];	// i일까지 얻을 수 있는 최대 수익

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &table[i][0], &table[i][1]);
	if (table[n][0] == 1)
		max_profit[n] = table[n][1];
	else
		max_profit[n] = 0;
	for (int i = n - 1; i >= 1; i--)
	{
		if (i + table[i][0] - 1 <= n)
			max_profit[i] = max(table[i][1] + max_profit[i + table[i][0] - 1], max_profit[i + 1]);
		else
			max_profit[i] = max_profit[i + 1];
	}
	printf("%d\n", max_profit[1]);
	return (0);
}
