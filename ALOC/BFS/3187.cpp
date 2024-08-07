#include	<iostream>
#include	<queue>
#include	<utility>

using namespace std;

queue<pair<int, int> >	q;
string					map[250];
int						visited[250][250];
int						r;
int						c;
int						total_sheep;
int						total_wolf;
int						dx[4] = {-1, 0, 1, 0};
int						dy[4] = {0, -1, 0, 1};

void	bfs(int x, int y)
{
	int	sheep;
	int	wolf;

	sheep = 0;
	wolf = 0;
	
	if (map[x][y] == 'k')
		sheep++;
	else if (map[x][y] == 'v')
		wolf++;
	visited[x][y] = 1;
	q.push(make_pair(x, y));
	while (!q.empty())
	{
		pair<int, int>	current = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int	new_x = current.first + dx[i];
			int	new_y = current.second + dy[i];
			if ((new_x >= 0 && new_x < r) && (new_y >= 0 && new_y < c) && map[new_x][new_y] != '#' && visited[new_x][new_y] == 0)
			{
				if (map[new_x][new_y] == 'k')
					sheep++;
				else if (map[new_x][new_y] == 'v')
					wolf++;
				visited[new_x][new_y] = 1;
				q.push(make_pair(new_x, new_y));
			}
		}
	}
	// cout << "sheep: " << sheep << ", wolf: " << wolf << "\n";
	if (sheep > wolf)
		wolf = 0;
	else
		sheep = 0;
	total_sheep += sheep;
	total_wolf += wolf;
}

int	main(void)
{
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		cin >> map[i];
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (map[i][j] != '#' && visited[i][j] == 0)
				bfs(i, j);
		}
	}
	cout << total_sheep << " " << total_wolf << "\n";
	return (0);
}
