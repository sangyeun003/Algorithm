// 방법1. 위->아래. 내려가면서 아래층에 더할 수 있는 숫자 중 Max를 더해줌. 맨 아래층에서 Max가 답.
// 방법2. 아래->위. 올라가면서 위층에 더할 수 있는 숫자 중 Max를 더해줌. 꼭대기에 있는게 답임.
#include	<iostream>

using namespace std;

int	max(int a, int b)
{
	return a > b ? a : b;
}

int	main(void)
{
	int	n;
	int	triangle[501][501];
	int	ans[501][501];

	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			cin >> triangle[i][j];
	// 방법2로 구현
	// 초기화
	for (int i = 1; i <= n; i++)
		ans[n][i] = triangle[n][i];
	// 점화식 구현
	for (int i = n - 1; i >= 1; i--)
		for (int j = 1; j <= i; j++)
			ans[i][j] = triangle[i][j] + max(ans[i + 1][j], ans[i + 1][j + 1]);
	cout << ans[1][1] << endl;
	return (0);
}
