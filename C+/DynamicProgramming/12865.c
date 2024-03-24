#include	<stdio.h>

int max(int a, int b)
{
	return (a > b ? a : b);
}

int	main(void)
{
	int	n;
	int	k;
	int	w[101];
	int	v[101];
	int	dp[101][10001];

	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &w[i], &v[i]);
	// 테이블 정의
	// dp[i][w]: 버틸 수 있는 무게가 w이고 i번째 물건까지 판단했을 때 max value
	
	// 점화식 찾기
	//	if (w[i] > k)
	//		dp[i][w] = dp[i - 1][w];
	//	else
	//		dp[i][w] = max(dp[i - 1][w], v[i] + dp[i][w - w[i]]);

	// 초기값 정하기
	for (int i = 0; i <= n; i++)
		dp[i][0] = 0;
	for (int weight = 0; weight <= k; weight++)
		dp[0][weight] = 0;
	for (int weight = 1; weight <= k; weight++)
	{
		for(int i = 1; i <= n; i++)
		{
			if (w[i] > weight)
				dp[i][weight] = dp[i - 1][weight];
			else
				dp[i][weight] = max(dp[i - 1][weight], v[i] + dp[i - 1][weight - w[i]]);
		}
	}
	// for (int i = 1; i <= n; i++)
	// {
	// 	for (int weight = 1; weight <= k; weight++)
	// 		printf("%d ", dp[i][weight]);
	// 	printf("\n");
	// }
	printf("%d\n", dp[n][k]);
	return (0);
}
