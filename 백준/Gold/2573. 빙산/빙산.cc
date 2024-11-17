#include	<iostream>

using namespace	std;

int	n;
int	m;
int	map[300][300];
int	decrease_amount[300][300] = {0};
int	visited[300][300];
int	dx[4] = {-1, 0, 1, 0};
int	dy[4] = {0, -1, 0, 1};

void	melting(void)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] > 0)
			{
				int	nx;
				int	ny;
				for (int k = 0; k < 4; k++)
				{
					nx = i + dx[k];
					ny = j + dy[k];
					if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] == 0)
						decrease_amount[i][j]--;
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < m; j++)
		{
			map[i][j] = map[i][j] + decrease_amount[i][j];
			if (map[i][j] < 0)
				map[i][j] = 0;
			decrease_amount[i][j] = 0;
		}
	}
}

void	dfs(int start_x, int start_y)
{
	visited[start_x][start_y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int	nx = start_x + dx[i];
		int	ny = start_y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] > 0 && visited[nx][ny] != 1)
			dfs(nx, ny);
	}
}


int	is_all_sea(void)
{
	int	flag;

	flag = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] != 0)
				flag = 0;
			visited[i][j] = 0;
		}
	}
	return (flag);
}

int	main(void)
{
	int	iceberg;
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	for (int year = 1; !is_all_sea(); year++)
	{
		iceberg = 0;
		melting();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (map[i][j] != 0 && visited[i][j] != 1)
				{
					dfs(i, j);
					iceberg++;
				}
			}
		}
		if (iceberg >= 2)
		{
			cout << year << "\n";
			return (0);
		}
	}
	cout << "0\n";
	return (0);
}
