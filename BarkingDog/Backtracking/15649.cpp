// 비어있는 리스트에서 시작
// 수를 한 개씩 추가하면서 길이가 M이 되면 출력
#include	<iostream>

using namespace	std;

int		n;
int		m;
int		num[8];
bool	is_used[9];

void	backtracking(int depth)
{
	if (depth == m)
	{
		for (int i = 0; i < m; i++)
			cout << num[i] << ' ';
		cout << "\n";
		return ;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!is_used[i])
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
