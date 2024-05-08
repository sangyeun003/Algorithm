#include	<stdio.h>

int		board[5][5];
int		dx[4] = {-1, 0, 1, 0};
int		dy[4] = {0, -1, 0, 1};
int		result = 0;

void	dfs(int x, int y, int depth, int ate)
{
	// printf("board[%d][%d]: %d\n", x, y, board[x][y]);
	if (board[x][y] == 1)
		ate++;
	if (depth == 3)
	{
		if (ate >= 2)
			result = 1;
		return ;
	}
	// 다음 칸 탐색
	for (int i = 0; i < 4; i++)
	{
		int	nx = x + dx[i];
		int	ny = y + dy[i];
		int	temp;
		// printf("%d %d\n", nx, ny);
		if (nx < 0 || nx > 4 || ny < 0 || ny > 4)
			continue ;
		if (board[nx][ny] == -1)
			continue ;
		temp = board[x][y];
		board[x][y] = -1;
		dfs(nx, ny, depth + 1, ate);
		board[x][y] = temp;
	}
}

int	main(void)
{
	int	x;
	int	y;

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			scanf("%d", &board[i][j]);
	// for (int i = 0; i < 5; i++)
	// {
	// 	for (int j = 0; j < 5; j++)
	// 	{
	// 		printf("%d ", board[i][j]);
	// 	}
	// 	printf("\n");
	// }
	scanf("%d %d", &x, &y);
	dfs(x, y, 0, 0);
	printf("%d\n", result);
	return (0);
}