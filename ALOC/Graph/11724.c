#include	<stdio.h>
#include	<stdlib.h>

typedef struct node
{
	int			x;
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

void	enqueue(Queue *q, int x)
{
	Node	*newnode;

	newnode = (Node *)malloc(sizeof(Node));
	if (!newnode)
		exit(1);
	newnode->x = x;
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

int		map[1001][1001];
int		visited[1001];
int		m;
int		n;
int		count;

Queue	q;

void	bfs(int	start)
{
	enqueue(&q, start);
	visited[start] = 1;
	// printf("%d ", start);
	while (!is_empty(&q))
	{
		start = q.front->x;
		dequeue(&q);
		for (int i = 1; i <= m; i++)
		{
			if (visited[i] != 1 && map[start][i] == 1)
			{
				enqueue(&q, i);
				visited[i] = 1;
				// printf("%d ", i);
			}
		}
	}
	// printf("\n");
}

int	main(void)
{
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++)
	{
		int	m1;
		int	m2;

		scanf("%d %d", &m1, &m2);
		map[m1][m2] = 1;
		map[m2][m1] = 1;
	}
	// 정점 개수만큼 BFS
	// DFS로 하려면 백트래킹해야할 거 같음
	init_queue(&q);
	for (int i = 1; i <= m; i++)
	{
		if (visited[i] != 1)
		{
			bfs(i);
			count++;
		}
	}
	printf("%d\n", count);
	return (0);
}
