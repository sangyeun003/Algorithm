#include	<iostream>
#include	<string>

using namespace std;

string	map[101];
int	visited[100][100];
int	r;
int	c;
int	dx[4] = {-1, 0, 1, 0};
int	dy[4] = {0, -1, 0, 1};

void	dfs(int start_x, int start_y)
{
	visited[start_x][start_y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int	x = start_x + dx[i];
		int	y = start_y + dy[i];

		if ((x >= 0 && x < r) && (y >= 0 && y < c) && map[x][y] == '1' && visited[x][y] == 0)
			dfs(x, y);
	}
}

void	clear_visited(void)
{
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			visited[i][j] = 0;
}

void	M(void)
{
	int		x;
	int		y;
	char	z;

	cin >> x >> y >> z;
	map[x][y] = z;
	return ;
}

void	Q(void)
{
	int	result;

	result = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (map[i][j] == '1' && visited[i][j] == 0)
			{
				dfs(i, j);
				result++;
			}
		}
	}
	cout << result << endl;
	clear_visited();
	return ;
}

int	main(void)
{
	int		t;

	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		int		n;
		char	operation;

		cout << "Case #" << i << ":" << endl;
		cin >> r >> c;
		for (int j = 0; j < r; j++)
			cin >> map[j];
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			cin >> operation;
			if (operation == 'M')
				M();
			else if (operation == 'Q')
				Q();
		}
	}
	return (0);
}
