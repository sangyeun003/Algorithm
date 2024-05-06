#include	<stdio.h>
#include	"queue.h"

int		n;
int		m;
int		paper[500][500] = {0};
int		visited[500][500] = {0};
int		dx[4] = {-1, 0, 1, 0};
int		dy[4] = {0, -1, 0, 1};
Queue	q;

int	bfs(int x, int y)
{
	int	nx;
	int	ny;
	int	area;

	visited[x][y] = 1;
	init_queue(&q);
	enqueue(&q, x, y);
	area = 1;
	while (!is_empty(&q))
	{
		x = q.front->x;
		y = q.front->y;
		dequeue(&q);
		for (int i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue ;
			if (visited[nx][ny] == 1 || paper[nx][ny] == 0)
				continue ;
			visited[nx][ny] = 1;
			enqueue(&q, nx, ny);
			area++;
		}
	}
	return (area);
}

int	main(void)
{
	int	count;
	int	max;
	int	area;

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &paper[i][j]);
	count = 0;
	max = 0;
	// for (int i = 0; i < n; i++)
	// {
	// 	for (int j = 0; j < m; j++)
	// 		printf("%d ", paper[i][j]);
	// 	printf("\n");
	// }
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visited[i][j] == 0 && paper[i][j] == 1)
			{
				count++;
				area = bfs(i, j);
				if (max < area)
					max = area;
			}
		}
	}
	printf("%d\n%d\n", count, max);
	return (0);
}
