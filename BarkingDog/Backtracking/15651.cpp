#include	<iostream>

using namespace std;

int	n;
int	m;
int	num[8];

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
		num[depth] = i;
		backtracking(depth + 1);
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
