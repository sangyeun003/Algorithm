#include	<iostream>

using namespace std;

int	n;
int	m;
int	num[8];
int	is_used[9];

void	backtracking(int depth)
{
	if (depth == m)
	{
		for (int i = 0; i < m; i++)
			cout << num[i] << " ";
		cout << "\n";
		return ;
	}
	for (int i = 1; i <= n; i++)
	{
		if (depth == 0 || num[depth - 1] < i)
		{
			num[depth] = i;
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
	backtracking(0);
	return (0);
}
