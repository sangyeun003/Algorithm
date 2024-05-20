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

int	n;
int	k;
int	map[100001];
int	result;

Queue	q;

int	main(void)
{
	scanf("%d %d", &n, &k);
	init_queue(&q);
	map[n] = 1;
	enqueue(&q, n);
	while (!is_empty(&q))
	{
		int	cur = q.front->x;
		dequeue(&q);
		if (cur == k)
		{
			printf("%d\n", map[cur] - 1);
			while (!is_empty(&q))
				dequeue(&q);
			return (0);
		}
		if (cur - 1 >= 0 && map[cur - 1] == 0)
		{
			map[cur - 1] = map[cur] + 1;
			enqueue(&q, cur - 1);
		}
		if (cur + 1 <= 100000 && map[cur + 1] == 0)
		{
			map[cur + 1] = map[cur] + 1;
			enqueue(&q, cur + 1);
		}
		if (2 * cur <= 100000 && map[2 * cur] == 0)
		{
			map[2 * cur] = map[cur] + 1;
			enqueue(&q, 2 * cur);
		}
		printf("%d: %d %d %d\n", cur, cur - 1, cur + 1, 2 * cur);
	}
	return (0);
}
