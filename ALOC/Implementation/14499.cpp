#include	<iostream>

using namespace std;

int	map[20][20];

// 주사위 관련 데이터
// vertical[1] == 바닥면
// vertical[3] == 윗면
int	vertical[4];
int	horizon[2];

void	north(void)
{
	int	temp;

	temp = vertical[3];
	for (int i = 3; i > 0; i--)
		vertical[i] = vertical[i - 1];
	vertical[0] = temp;
}

void	south(void)
{
	int	temp;

	temp = vertical[0];
	for (int i = 1; i < 4; i++)
		vertical[i - 1] = vertical[i];
	vertical[3] = temp;
}

void	west(void)
{
	int	temp;

	temp = horizon[1];
	horizon[1] = vertical[1];
	vertical[1] = horizon[0];
	horizon[0] = vertical[3];
	vertical[3] = temp;
}

void	east(void)
{
	int	temp;

	temp = horizon[0];
	horizon[0] = vertical[1];
	vertical[1] = horizon[1];
	horizon[1] = vertical[3];
	vertical[3] = temp;
}

void	update(int x, int y)
{
	if (map[x][y] == 0)
		map[x][y] = vertical[1];
	else
	{
		vertical[1] = map[x][y];
		map[x][y] = 0;
	}
}

int	main(void)
{
	int	n;
	int	m;
	int	x;
	int	y;
	int	k;
	int	cmd;

	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	for (int i = 0; i < k; i++)
	{
		cin >> cmd;
		if (cmd == 1)
		{
			if (y + 1 < m)
			{
				east();
				y++;
				update(x, y);
				cout << vertical[3] << "\n";
			}
		}
		else if (cmd == 2)
		{
			if (y - 1 >= 0)
			{
				west();
				y--;
				update(x, y);
				cout << vertical[3] << "\n";
			}
		}
		else if (cmd == 3)
		{
			if (x - 1 >= 0)
			{
				north();
				x--;
				update(x, y);
				cout << vertical[3] << "\n";
			}
		}
		else if (cmd == 4)
		{
			if (x + 1 < n)
			{
				south();
				x++;
				update(x, y);
				cout << vertical[3] << "\n";
			}
		}
	}
	return (0);
}
