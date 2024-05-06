#include	<stdio.h>
#include	"queue.h"

char	map[100][100];
int		distance[100][100] = {0};
int		dx[4] = {-1, 0, 1, 0};
int		dy[4] = {0, -1, 0, 1};
int		n;
int		m;
Queue	q;

void	bfs(void)
{
	int	x;
	int	y;
	int	nx;
	int	ny;

	init_queue(&q);
	distance[0][0] = 1;
	enqueue(&q, 0, 0);
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
			if (map[nx][ny] != '1' || distance[nx][ny] != 0)
				continue ;
			distance[nx][ny] = distance[x][y] + 1;
			enqueue(&q, nx, ny);
		}
	}
}

int	main(void)
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", map[i]);
	bfs();
	// for (int i = 0; i < n; i++)
	// {
	// 	for (int j = 0; j < m; j++)
	// 		printf("%d ", distance[i][j]);
	// 	printf("\n");
	// }
	printf("%d\n", distance[n - 1][m - 1]);
	return (0);
}
