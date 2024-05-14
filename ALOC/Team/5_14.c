#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node
{
	int			x;
	int			y;
	struct node	*next;
}	Node;

typedef struct queue
{
	Node	*front;
	Node	*rear;
	int		count;
}	Queue;

void	init_queue(Queue *q)
{
	q->front = NULL;
	q->rear = NULL;
	q->count = 0;
}

int	is_empty(Queue *q)
{
	return (q->front == NULL);
}

void	enqueue(Queue *q, int x, int y)
{
	Node	*newnode;

	newnode = (Node *)malloc(sizeof(Node));
	if (!newnode)
		exit(1);
	newnode->x = x;
	newnode->y = y;
	newnode->next = NULL;
	if (is_empty(q))
	{
		q->front = newnode;
		q->rear = newnode;
	}
	else
	{
		q->rear->next = newnode;
		q->rear = newnode;
	}
	q->count++;
}

void	dequeue(Queue *q)
{
	Node	*del;

	if (is_empty(q))
		exit(1);
	del = q->front;
	q->front = q->front->next;
	free(del);
	q->count--;
	return ;
}

Queue	q;
int		dx[4] = {-1, 0, 1, 0};
int		dy[4] = {0, -1, 0, 1};
int		visited[51][51];

int	is_in(int **rectangle, size_t rectangle_row_len, int x, int y)
{
	for (int i = 0; i < rectangle_row_len; i++)
	{
		int	x1 = rectangle[i][0];
		int	y1 = rectangle[i][1];
		int	x2 = rectangle[i][2];
		int	y2 = rectangle[i][3];
		if ((x > x1 && x < x2) && (y > y1 && y < y2))
			return (1);
	}
	return (0);
}

int	is_road(int **rectangle, size_t rectangle_row_len, int x, int y)
{
	for (int i = 0; i < rectangle_row_len; i++)
	{
		int	x1 = rectangle[i][0];
		int	y1 = rectangle[i][1];
		int	x2 = rectangle[i][2];
		int	y2 = rectangle[i][3];
		if ((x >= x1 && x <= x2) && (y == y1 || y == y2))
			return (1);
		if ((x == x1 || x == x2) && (y >= y1 || y <= y2))
			return (1);
	}
	return (0);
}

// rectangle_row_len은 2차원 배열 rectangle의 행(세로) 길이입니다.
// rectangle_col_len은 2차원 배열 rectangle의 열(가로) 길이입니다.
// rectangle[i][j]는 rectangle의 i번째 행의 j번째 열에 저장된 값을 의미합니다.
int solution(int **rectangle, size_t rectangle_row_len, size_t rectangle_col_len, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
	
	init_queue(&q);
	enqueue(&q, characterX, characterY);
	visited[characterX][characterY];
	while (!is_empty(&q))
	{
		int	x = q.front->x;
		int	y = q.front->y;
		dequeue(&q);
		for (int i = 0; i < 4; i++)
		{
			int	nx = x + dx[i];
			int	ny = y + dy[i];
			if (visited[nx][ny] == 1 || is_in(rectangle, rectangle_row_len, nx, ny) || !is_road(rectangle, rectangle_row_len, nx, ny))
				continue ;
			if (nx == itemX && ny == itemY)
			{
				while (!is_empty(&q))
					dequeue(&q);
				return (answer / 2);
			}
			enqueue(&q, nx, ny);
			visited[nx][ny] = 1;
			answer++;
		}
	}
}
