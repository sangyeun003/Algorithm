#include	<iostream>

using namespace std;

int	n;
int	m;
int	map[8][8];
int	visited[8][8];
int	dx[4] = {-1, 0, 1, 0};
int	dy[4] = {0, -1, 0, 1};
int	result;

void	set_visited(void)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			visited[i][j] = map[i][j];
}

void	dfs(int x, int y)
{
	int	new_x;
	int	new_y;

	for (int i = 0; i < 4; i++)
	{
		new_x = x + dx[i];
		new_y = y + dy[i];
		if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m)
		{
			if (visited[new_x][new_y] == 0)
			{
				visited[new_x][new_y] = 2;
				dfs(new_x, new_y);
			}
		}
	}
}

int	count(void)
{
	int	safe_area;

	safe_area = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (visited[i][j] == 0)
				safe_area++;
	return (safe_area);
}

void	search(void)
{
	int	max;

	for (int x = 0; x < n; x++)
		for (int y = 0; y < m; y++)
			if (visited[x][y] == 2)
				dfs(x, y);
	max = count();
	if (max > result)
		result = max;
}

int	main(void)
{	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	result = 0;
	for (int i = 0; i < n * m; i++)
	{
		if (map[i / m][i % m] == 0)
		{
			map[i / m][i % m] = 1;
			for (int j = i + 1; j < n * m; j++)
			{
				if (map[j / m][j % m] == 0)
				{
					map[j / m][j % m] = 1;
					for (int k = j + 1; k < n * m; k++)
					{
						if (map[k / m][k % m] == 0)
						{
							map[k / m][k % m] = 1;
							set_visited();
							search();
							map[k / m][k % m] = 0;
						}
					}
					map[j / m][j % m] = 0;
				}
			}
			map[i / m][i % m] = 0;
		}
	}
	cout << result;
	return (0);
}
