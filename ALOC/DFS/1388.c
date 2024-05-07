#include	"stack.h"
#include	<stdio.h>

char	map[50][50];
int		visited[50][50];
int		m;
int		n;
Stack	s;

void	dfs(int x, int y, char c)
{
	int	nx;
	int	ny;

	if (c == '|')
	{
		while (!is_stack_empty(&s))
		{
			x = s.top->x;
			y = s.top->y;
			pop(&s);
			nx = x + 1;
			if (nx < 0 || nx >= m)
				continue;
			if (visited[nx][y] == 1 || map[nx][y] != c)
				continue ;
			push(&s, nx, y);
			visited[nx][y] = 1;
		}
	}
	else if (c == '-')
	{
		while (!is_stack_empty(&s))
		{
			x = s.top->x;
			y = s.top->y;
			pop(&s);
			ny = y + 1;
			if (ny < 0 || ny >= n)
				continue;
			if (visited[x][ny] == 1 || map[x][ny] != c)
				continue ;
			push(&s, x, ny);
			visited[x][ny] = 1;
		}
	}
}

int	main(void)
{
	int	count;

	scanf("%d %d", &m, &n);
	for (int i = 0; i < m; i++)
		scanf("%s", map[i]);	// 개행까지만 입력 받음
	init_stack(&s);
	count = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j] == 0)
			{
				visited[i][j] = 1;
				push(&s, i, j);
				dfs(i, j, map[i][j]);
				count++;
			}
		}
	}
	// for (int i = 0; i < m; i++)
	// {
	// 	for (int j = 0; j < n; j++)
	// 		printf("%d ", visited[i][j]);
	// 	printf("\n");
	// }
	printf("%d\n", count);
	return (0);
}
