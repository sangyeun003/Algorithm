#include	<iostream>

using namespace std;

int	num[10001];

int	main(void)
{
	int	m;
	int	n;
	int	min;
	int	result;

	for (int i = 1; i * i <= 10000; i++)
		num[i * i] = 1;
	cin >> m >> n;
	result = 0;
	for (int i = n; i >= m; i--)
	{
		if (num[i] == 1)
		{
			result += i;
			min = i;
		}
	}
	if (result == 0)
		cout << "-1\n";
	else
		cout << result << "\n" << min << "\n";
	return (0);
}
