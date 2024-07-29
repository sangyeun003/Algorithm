#include	<iostream>

using namespace std;

int	main(void)
{
	int	prime[10001] = {0};
	int	t;
	int	n;
	int	result;

	prime[0] = -1;
	prime[1] = -1;
	for (int i = 2; i <= 10000; i++)
	{
		if (prime[i] != -1)
		{
			prime[i] = 1;
			for (int j = 2; i * j <= 10000; j++)
				prime[i * j] = -1;
		}
		// cout << "num: " << i << ", " << prime[i] << endl;
	}
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		for (int j = 2; j <= n / 2; j++)
		{
			if (prime[j] == 1 && prime[n - j] == 1)
				result = j;
		}
		cout << result << ' ' << n - result << endl;
	}
	return (0);
}
