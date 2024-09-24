#include	<iostream>

using namespace std;

int	n;
int	levels[1000000];
int	k;

int	find_min(void)
{
	int	result;

	result = levels[0];
	for (int i = 1; i < n; i++)
	{
		if (levels[i] < result)
			result = levels[i];
	}
	return (result);
}

long long	level_up(int level)	// 목표를 level로 하기 위해 올려야 하는 레벨의 총합
{
	long long	result;

	result = 0;
	for (int i = 0; i < n; i++)
	{
		if (levels[i] < level)
			result += level - levels[i];
	}
	return (result);
}

int	binary_search(void)
{
	int			left;
	int			mid;
	int			right;
	long long	total_to_level_up;
	int			result;

	left = find_min();
	right = left + k;
	result = left;
	while (left <= right)
	{
		mid = (left + right) / 2;
		total_to_level_up = level_up(mid);
		if (total_to_level_up > k)
			right = mid - 1;
		else if (total_to_level_up < k)
		{
			result = mid;
			left = mid + 1;
		}
		else
		{
			result = mid;
			break;
		}
	}
	return (result);
}

int	main(void)
{
	cin >> n;
	cin >> k;
	for (int i = 0; i < n; i++)
		cin >> levels[i];
	cout << binary_search();
	return (0);
}
