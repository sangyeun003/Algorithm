// input max = 100000000
// 최대 0의 개수가 100000000까지 5의 배수의 개수
// 100000000 안의 5 인자의 개수는 약 (100000000 / 5) 개
// 따라서 right = 5 * 100000000에서 시작해야 함
#include	<iostream>

using namespace std;

int	num_of_0_to_n(int n)
{
	int	result;

	result = 0;
	while (n)
	{
		n /= 5;
		result += n;
	}
	return (result);
}

int	binary_search(int m)
{
	int	left;
	int	mid;
	int	right;
	int	zeros;
	int	result;

	result = -1;
	left = 1;
	right = 100000000 * 5;
	while (left <= right)
	{
		mid = (left + right) / 2;
		zeros = num_of_0_to_n(mid);
		if (m < zeros)
			right = mid - 1;
		else if (m > zeros)
			left = mid + 1;
		else
		{
			result = mid;
			right = mid - 1;
		}
	}
	return (result);
}

int	main(void)
{
	int	m;

	cin >> m;
	// cout << num_of_0_to_n(100) << "\n";
	cout << binary_search(m);
	return (0);
}