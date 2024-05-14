#include	"stack.h"
#include	<stdio.h>

int	compare(const void *a, const void *b)
{
	int	num1;
	int	num2;

	num1 = *(int *)a;
	num2 = *(int *)b;
	if (num1 < num2)
		return (-1);
	if (num1 > num2)
		return (1);
	return (0);
}

char	map[25][25];
int		houses[400];	// 13 * 13 + 12 * 12 = 313 이상으로 해줘야 함
int		n;
int		dx[4] = {-1, 0, 1, 0};
int		dy[4] = {0, -1, 0, 1};

Stack	s;

int	main(void)
{
	int	count;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%s", map[i]);
	count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == '1')
			{
				init_stack(&s);
				push(&s, i, j);
				map[i][j] = '0';
				houses[count]++;
				count++;
				while (!is_stack_empty(&s))
				{
					int	x = s.top->x;
					int	y = s.top->y;
					int	k;
					for (k = 0; k < 4; k++)
					{
						int	nx = x + dx[k];
						int	ny = y + dy[k];
						if (nx < 0 || nx >= n || ny < 0 || ny >= n || map[nx][ny] == '0')
							continue ;
						push(&s, nx, ny);
						map[nx][ny] = '0';
						houses[count - 1]++;
						break ;
					}
					if (k >= 4)
						pop(&s);
				}
			}
		}
	}
	printf("%d\n", count);
	qsort(houses, count, sizeof(int), compare);
	for (int i = 0; houses[i] != 0; i++)
		printf("%d\n", houses[i]);
	return (0);
}
