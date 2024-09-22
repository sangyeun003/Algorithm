#include	<iostream>

using namespace	std;

int	main(void)
{
	int		n;
	long	result;

	cin >> n;
	result = 1;
	for (long i = 2; i <= n; i++)
	{
		result *= i;
		if (i % 5 == 0)
			result /= 10;
		while (result % 10 == 0)
			result /= 10;
		result %= 1000000000000;
	}
	result %= 100000;
	if (result < 10)
		cout << '0';
	if (result < 100)
		cout << '0';
	if (result < 1000)
		cout << '0';
	if (result < 10000)
		cout << '0';
	cout << result;
	return (0);
}
