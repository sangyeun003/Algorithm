#include	<iostream>

using namespace	std;

int	n;
int	map[100][100];
int	visited[100][100];

int	dx[4] = {-1, 0, 1, 0};
int	dy[4] = {0, -1, 0, 1};

void	clear_visited(void)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			visited[i][j] = 0;
}

void	dfs(int height, int start_x, int start_y)
{
	visited[start_x][start_y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int new_x = start_x + dx[i];
		int new_y = start_y + dy[i];
		if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < n && visited[new_x][new_y] != 1)
		{
			if (map[new_x][new_y] > height)
				dfs(height, new_x, new_y);
		}
	}
}

int	main(void)
{
	int	min_height;
	int	max_height;
	int	max_safe_area;
	int	safe_area;

	cin >> n;
	min_height = 100;
	max_height = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			if (map[i][j] < min_height)
				min_height = map[i][j];
			if (map[i][j] > max_height)
				max_height = map[i][j];
		}
	}
	max_safe_area = 0;
	// min_height - 1부터 시작하는 이유: ex. 높이가 3으로 전부 같은 경우 3부터 시작하면 안전지대가 0개임. 모든 지역이 물에 안잠길 수 있음.
	for (int i = min_height - 1; i <= max_height; i++)
	{
		safe_area = 0;
		clear_visited();
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (visited[j][k] != 1 && map[j][k] > i)
				{
					dfs(i, j, k);
					safe_area++;
				}
			}
		}
		if (max_safe_area < safe_area)
			max_safe_area = safe_area;
	}
	cout << max_safe_area << "\n";
	return (0);
}