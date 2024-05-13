#include	<stdio.h>
# include	<stdlib.h>

typedef	struct node
{
	int			x;
	struct node	*next;
}	Node;

typedef struct stack
{
	Node	*top;
	int		count;
}	Stack;

typedef struct queue
{
	Node	*front;
	Node	*rear;
	int		count;
}	Queue;

void	init_stack(Stack *s)
{
	s->top = NULL;
	s->count = 0;
}

int		is_stack_empty(Stack *s)
{
	return (s->top == NULL);
}

void	push(Stack *s, int x)
{
	Node	*newnode;

	newnode = (Node *)malloc(sizeof(Node));
	if (!newnode)
		exit(1);
	newnode->x = x;
	newnode->next = s->top;
	s->top = newnode;
	s->count++;
}

void	pop(Stack *s)
{
	if (is_stack_empty(s))
		return ;
	Node	*del;

	del = s->top;
	s->top = del->next;
	free(del);
	s->count--;
}

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

int		n;
int		m;
int		v;
int		map[1001][1001];
int		visited_dfs[1001];
int		visited_bfs[1001];

Stack	s;
Queue	q;

int	main(void)
{
	int	current;
	
	scanf("%d %d %d", &n, &m, &v);
	for (int i = 0; i < m; i++)
	{
		int	temp1;
		int	temp2;

		scanf("%d %d", &temp1, &temp2);
		map[temp1][temp2] = 1;
		map[temp2][temp1] = 1;
	}
	init_stack(&s);
	// DFS
	current = v;
	push(&s, current);
	visited_dfs[current] = 1;
	printf("%d ", current);
	while (!is_stack_empty(&s))
	{
		current = s.top->x;
		int	i;
		for (i = 1; i <= n; i++)
		{
			if (map[current][i] == 1 && visited_dfs[i] != 1)
			{
				push(&s, i);
				visited_dfs[i] = 1;
				printf("%d ", i);
				break ;
			}
		}
		// (중요) 탐색 다 하고 나서 맨 마지막에 pop 해야함
		if (i > n)
			pop(&s);
	}
	printf("\n");
	// BFS
	init_queue(&q);
	current = v;
	enqueue(&q, current);
	visited_bfs[current] = 1;
	printf("%d ", current);
	while (!is_empty(&q))
	{
		current = q.front->x;
		dequeue(&q);
		for (int i = 1; i <= n; i++)
		{
			if (map[current][i] == 1 && visited_bfs[i] != 1)
			{
				enqueue(&q, i);
				visited_bfs[i] = 1;
				printf("%d ", i);
			}
		}
	}
	printf("\n");
	return (0);
}
