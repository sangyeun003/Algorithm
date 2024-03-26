// (1, 1) -> (m, n)
// path[i][j]: (i, j)로 갈 수 있는 경로의 수
// 그냥 반복문 돌리려고 했는데 이건 최단 경로임. 모든 경우를 확인할 수 없음.
// memoization하면서 dfs
// dfs해서 (i, j)까지 갔다는 건, 거기까지 가는게 가능하다는 것.
// path[i][j] == -1이면 아직 방문을 안해서 값을 줘야된다는 것이고, -1이 아니면
// memoization으로 값을 바로 갖고올 수 있음.
#include	<stdio.h>

int	m;
int	n;
int	map[501][501];
int	path[501][501];
int	dx[4] = {-1, 1, 0, 0};
int	dy[4] = {0, 0, -1, 1};

int	dfs(int x, int y) // (x, y) -> (m, n) 가능한 경로의 수
{
	int	nx;
	int	ny;
	
	if (x == n && y == m)
		return (1);
	if (path[y][x] != -1)
		return (path[y][x]);
	path[y][x] = 0;
	for (int i = 0; i < 4; i++)
	{
		nx = x + dx[i];
		ny = y + dy[i];
		if ((nx >= 1 && nx <= n) && (ny >= 1 && ny <= m))
		{
			if (map[ny][nx] < map[y][x])
				path[y][x] += dfs(nx, ny);
		}
	}
	return (path[y][x]);
}

int	main(void)
{
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &map[i][j]);
			path[i][j] = -1;
		}
	}
	printf("%d\n", dfs(1, 1));
	return (0);
}
