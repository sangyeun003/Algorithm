#include	"stack.h"

void	init_stack(Stack *s)
{
	s->top = NULL;
	s->count = 0;
}

int		is_stack_empty(Stack *s)
{
	return (s->top == NULL);
}

void	push(Stack *s, int x, int y)
{
	Node	*newnode;

	newnode = (Node *)malloc(sizeof(Node));
	if (!newnode)
		exit(1);
	newnode->x = x;
	newnode->y = y;
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
