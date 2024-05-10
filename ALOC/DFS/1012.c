#include	<stdio.h>
#include	"stack.h"

int		map[50][50];
int		m;
int		n;
int		k;
int		result;

int	dx[4] = {-1, 0, 1, 0};
int	dy[4] = {0, -1, 0, 1};

Stack	s;

void	reset_map(void)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			map[i][j] = 0;
}

void	dfs(int x, int y)
{
	init_stack(&s);
	if (map[x][y] != 1)
		return ;
	push(&s, x, y);
	map[x][y] = 2;
	result++;
	while (!is_stack_empty(&s))
	{
		x = s.top->x;
		y = s.top->y;
		pop(&s);
		for (int i = 0; i < 4; i++)
		{
			int	nx = x + dx[i];
			int	ny = y + dy[i];

			if (nx < 0 || nx >= m || ny < 0 || ny >= n)
				continue ;
			if (map[nx][ny] != 1)
				continue ;
			push(&s, nx, ny);
			map[nx][ny] = 2;
		}
	}
}

int	main(void)
{
	int	t;

	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		reset_map();
		result = 0;
		scanf("%d %d %d", &m, &n, &k);
		for (int cabbage = 0; cabbage < k; cabbage++)
		{
			int	x;
			int	y;

			scanf("%d %d", &x, &y);
			map[x][y] = 1;
		}
		for (int x = 0; x < m; x++)
			for (int y = 0; y < n; y++)
				dfs(x, y);
		printf("%d\n", result);
	}
}