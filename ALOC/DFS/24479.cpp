// cin, cout 쓰면 시간초과 나서 scanf, printf 썼더니 통과
#include	<iostream>
#include	<vector>

using namespace std;

int	visited[100001];
vector<int>	map[100001];
int	cnt = 1;

void	dfs(int r)
{
	if (visited[r] != 0)
		return ;
	visited[r] = cnt;
	cnt++;
	for (int i = 0; i < map[r].size(); i++)
	{
		if (visited[map[r][i]] == 0)
			dfs(map[r][i]);
	}
}

int	main(void)
{
	int	n;
	int	m;
	int	r;

	scanf("%d %d %d", &n, &m, &r);
	for (int i = 0; i < m; i++)
	{
		int	t1;
		int	t2;
		scanf("%d %d", &t1, &t2);
		map[t1].push_back(t2);
		map[t2].push_back(t1);
	}
	// map[i] 별 정렬
	for (int i = 1; i <= n; i++)
		sort(map[i].begin(), map[i].end());	// begin과 end는 정렬 범위를 나타냄

	dfs(r);
	for (int i = 1; i <= n; i++)
		printf("%d\n", visited[i]);
	return (0);
}
