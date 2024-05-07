#include	<stdlib.h>
#include	<stdio.h>

typedef struct node
{
	int			x;
	int			y;
	int			value;
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

void	enqueue(Queue *q, int x, int y, int value)
{
	Node	*newnode;

	newnode = (Node *)malloc(sizeof(Node));
	if (!newnode)
		exit(1);
	newnode->x = x;
	newnode->y = y;
	newnode->value = value;
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

int	map[100][100];
int	visited[100][100];
int	m;
int	n;

int	dx[4] = {-1, 0, 1, 0};
int	dy[4] = {0, -1, 0, 1};

int	ret1;
int	ret2;

Queue	q;

void	bfs(int i, int j)
{
	enqueue(&q, i, j, map[i][j]);
	visited[i][j] = 1;
	while (!is_empty(&q))
	{
		i = q.front->x;
		j = q.front->y;
		dequeue(&q);
		for (int t = 0; t < 4; t++)
		{
			if (i < 0 || i >= m || j < 0 || j >= m)
				continue ;
			if (map[i][j] )
		}
	}
}

void	solution(void)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			bfs(i, j);
		}
	}
}

int	main(void)
{
	scanf("%d %d", &m, &n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	init_queue(&q);
	solution();
}
