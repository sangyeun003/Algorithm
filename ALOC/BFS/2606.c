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

int		map[101][101];
int		visited[101];
Queue	q;

int	main(void)
{
	int	computer;
	int	n;
	int	count;

	scanf("%d", &computer);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int	tmp1;
		int	tmp2;
		scanf("%d %d", &tmp1, &tmp2);
		map[tmp1][tmp2] = 1;
		map[tmp2][tmp1] = 1;
	}
	init_queue(&q);
	enqueue(&q, 1);
	visited[1] = 1;
	count = 0;
	while (!is_empty(&q))
	{
		int	x = q.front->x;
		dequeue(&q);
		for (int i = 2; i <= computer; i++)
		{
			if (map[x][i] == 1 && visited[i] != 1)
			{
				enqueue(&q, i);
				visited[i] = 1;
				count++;
			}
		}
	}
	printf("%d\n", count);
	return (0);
}
