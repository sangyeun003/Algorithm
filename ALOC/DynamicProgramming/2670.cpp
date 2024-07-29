#include	<iostream>
#include	<iomanip>

using namespace std;

int	main(void)
{
	double	num[10000];
	double	dp[10000];
	double	result;
	int		n;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	dp[0] = num[0];
	for (int i = 1; i < n; i++)
	{
		if (dp[i - 1] <= 1)
			dp[i] = num[i];
		else
			dp[i] = dp[i - 1] * num[i];
	}
	result = dp[0];
	for (int i = 1; i < n; i++)
	{
		if (dp[i] > result)
			result = dp[i];
	}
	cout << fixed << setprecision(3) << result << endl;
	return (0);
}
