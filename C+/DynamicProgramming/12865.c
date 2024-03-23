#include	<stdio.h>

int	main(void)
{
	int	n;
	int	k;
	int	w[101];
	int	v[101];
	int	dp[101][100001];

	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &w[i], &v[i]);
	// 테이블 정의
	// dp[i][w]: 버틸 수 있는 무게가 w이고 i번째 물건까지 판단했을 때 max value
	
}
