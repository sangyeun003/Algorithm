#ifndef	STACK_H

# include	<stdlib.h>

typedef	struct node
{
	int			x;
	int			y;
	struct node	*next;
}	Node;

typedef struct stack
{
	Node	*top;
	int		count;
}	Stack;

void	init_stack(Stack *s);
int		is_stack_empty(Stack *s);
void	push(Stack *s, int x, int y);
void	pop(Stack *s);

#endif