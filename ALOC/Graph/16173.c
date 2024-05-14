#include	"queue.h"
#include	<stdio.h>

int		map[3][3];
int		n;
int		dx[2] = {0, 1};
int		dy[2] = {1, 0};
Queue	q;

int	main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &map[i][j]);
	init_queue(&q);
	enqueue(&q, 0, 0);
	while (!is_empty(&q))
	{
		int	x = q.front->x;
		int	y = q.front->y;
		dequeue(&q);
		for (int i = 0; i < 2; i++)
		{
			int	nx = x + map[x][y] * dx[i];
			int	ny = y + map[x][y] * dy[i];
			// 아래 조건에서 map[nx][ny] == 0 안해주면 무한 루프 가능
			if (nx >= n || ny >= n || map[nx][ny] == 0)
				continue ;
			if (nx == n - 1 && ny == n - 1)
			{
				printf("HaruHaru\n");
				return (0);
			}
			enqueue(&q, nx, ny);
		}
	}
	printf("Hing\n");
	return (0);
}
