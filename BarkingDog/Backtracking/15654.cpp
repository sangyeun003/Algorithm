#include	<iostream>
#include	<algorithm>

using namespace std;

int		n;
int		m;
int		nums[8];
int		result[8];
bool	is_used[8];

void	backtracking(int depth)
{
	if (depth == m)
	{
		for (int i = 0; i < m; i++)
			cout << result[i] << " ";
		cout << "\n";
		return ;
	}
	for (int i = 0; i < n; i++)
	{
		if (!is_used[i])
		{
			result[depth] = nums[i];
			is_used[i] = true;
			backtracking(depth + 1);
			is_used[i] = false;
		}
	}
}

int	main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	sort(nums, nums + n);
	backtracking(0);
	return (0);
}
