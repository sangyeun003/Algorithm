#include	<iostream>

using namespace	std;

int	main(void)
{
	ios::sync_with_stdio(0);
    cin.tie(0);
	
	int	map[102][102] = {0};
	int	dp[102][102] = {0};
	int	n;
	int	m;
	int	x1, y1, x2, y2;

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> map[i][j];
	// 초기화
	// 배열을 0으로 초기화하면 안해도 점화식 초기화 안해도 됨
	// dp[1][1] = map[1][1];
	// for (int i = 2; i <= n; i++)
	// {
	// 	dp[1][i] = dp[1][i - 1] + map[1][i];
	// 	dp[i][1] = dp[i - 1][1] + map[i][1];
	// }
	// 점화식
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + map[i][j];
		}
	}
	// cout << "\n\n";
	// for (int i = 1; i <= n; i++)
	// {
	// 	for (int j = 1; j <= n; j++)
	// 		cout << dp[i][j] << " ";
	// 	cout << "\n";
	// }
	// cout << "\n\n";
	for (int i = 0; i < m; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		// 배열을 0으로 초기화하면 안해도 케이스 안나눠도 됨
		// if (x1 == 1 && y1 == 1)
		// 	cout << dp[x2][y2]<< "\n";
		// else if (x1 == 1)
		// 	cout << dp[x2][y2] - dp[x2][y1 - 1] << "\n";
		// else if (y1 == 1)
		// 	cout << dp[x2][y2] - dp[x1 - 1][y2] << "\n";
		// else 
			cout << dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1] << "\n";
	}
	return (0);
}
