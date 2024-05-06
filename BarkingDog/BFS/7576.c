// 익은 토마토들 각각을 시작점으로 BFS
// 모든 시작점을 queue에 넣고 시작
#include	<stdio.h>
#include	"queue.h"

int		n;
int		m;
int		box[1000][1000];
int		distance[1000][1000];
int		dx[4] = {-1, 0, 1, 0};
int		dy[4] = {0, -1, 0, 1};
Queue	q;

int	main(void)
{
	int	x;
	int	y;
	int	nx;
	int	ny;
	int	max;

	init_queue(&q);
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &box[i][j]);
			if (box[i][j] == 1)
				enqueue(&q, i, j);
			else if (box[i][j] == 0)
				distance[i][j] = -1;
		}
	}
	max = 0;
	while (!is_empty(&q))
	{
		x = q.front->x;
		y = q.front->y;
		if (distance[x][y] > max)
			max = distance[x][y];
		dequeue(&q);
		for (int i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue ;
			if (distance[nx][ny] >= 0)	// 이미 익었거나 빈 칸이거나
				continue ;
			distance[nx][ny] = distance[x][y] + 1;
			enqueue(&q, nx, ny);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (distance[i][j] == -1)
			{
				printf("-1\n");
				return (0);
			}
		}
	}
	printf("%d\n", max);
	return (0);
}
