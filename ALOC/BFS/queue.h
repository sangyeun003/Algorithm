#ifndef	QUEUE_H

# include	<stdlib.h>

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

void	init_queue(Queue *q);
int		is_empty(Queue *q);
void	enqueue(Queue *q, int x, int y);
void	dequeue(Queue *q);

#endif