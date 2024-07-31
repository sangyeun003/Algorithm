// cin, cout 쓰면 시간초과 나서 scanf, printf 썼더니 통과
#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace std;

int	visited[100001];
vector<int>	map[100001];

void	dfs(int r, int cnt)
{
	visited[r] = cnt;
	for (int i = 0; i < map[r].size(); i++)
	{
		if (visited[map[r][i]] == -1)
			dfs(map[r][i], cnt + 1);
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
	for (int i = 1; i <= n; i++)
		visited[i] = -1;
	// map[i]별 정렬
	for (int i = 1; i <= n; i++)
		sort(map[i].begin(), map[i].end());

	dfs(r, 0);
	for (int i = 1; i <= n; i++)
		printf("%d\n", visited[i]);
	return (0);
}
