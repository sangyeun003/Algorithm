// dp[i] = a[i]로 시작하는 수열 중 가장 긴 감소하는 부분수열
// n번째 항부터 채움
#include	<stdio.h>

int	main(void)
{
	int	n;
	int	a[1001];
	int	dp[1001];
	int	max;
	int	result;

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	dp[n] = 1;
	result = dp[n];
	for (int i = n - 1; i >= 1; i--)
	{
		max = 0;
		for (int j = i + 1; j <= n; j++)
		{
			if (a[i] > a[j] && dp[j] > max)
				max = dp[j];
		}
		dp[i] = max + 1;
		if (dp[i] > result)
			result = dp[i];
		// printf("dp[%d]: %d\n", i, dp[i]);
	}
	printf("%d\n", result);
	return (0);
}
