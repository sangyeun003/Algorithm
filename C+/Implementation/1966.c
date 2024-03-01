#include    <stdio.h>
#include	<stdlib.h>

typedef struct document
{
    int num;
    int priority;
}   Doc;

typedef struct queue
{
    Doc     docs[100];
    int     top;
	int		num;
}   Queue;


void    enqueue(Doc doc, Queue *queue, int index)
{
    queue->docs[(queue->top + queue->num) % 100] = doc;
	queue->num++;
}

Doc    dequeue(Queue *queue)
{
    Doc	temp;

	temp.num = queue->docs[queue->top].num;
	temp.priority = queue->docs[queue->top].priority;
	queue->top = (queue->top + 1) % 100;
	return (temp);
}

int	find_max(Queue *q)
{
	int	max_priority;
	int	max_num;

	max_priority = q->docs[q->top].priority;
	for (int i = q->top; i < (q->top + q->num) % 100; i = (i + 1) % 100)
		if (max_priority < q->docs[i].priority)
		{
			max_priority = q->docs[i].priority;
			max_num = q->docs[i].num;
		}
	return (max_num);
}

int main(void)
{
    Queue   *q;
    int     t;
    int     n;
    int     m;
	int		order;

    scanf("%d", &t);
    
	for (int i = 0; i < t; i++)
	{
		scanf("%d %d", &n, &m);
		q = malloc(sizeof(Queue));
		q->num = 0;
		q->top = 0;
		for (int j = 0; j < n; j++)
		{
			q->docs[j].num = j;
			scanf("%d", &q->docs[j].priority);
		}
		order = 0;
		while (1)
		{
			if (q->docs[q->top] == m)
				break ;
			
			order++;
		}
		printf("")
		free(q);
	}
}
