// 스택
#include	<stdio.h>

int	stack[100000];
int	stack_pointer = 0;	// 데이터를 넣어야 할 위치

void	push(int n)
{
	stack[stack_pointer] = n;
	stack_pointer++;
}

void	pop(void)
{
	if (stack_pointer == 0)
		return ;
	stack_pointer--;
	stack[stack_pointer] = 0;
	return ;
}

int		sum(void)
{
	int	result;

	result = 0;
	for (int i = 0; i < stack_pointer; i++)
		result += stack[i];
	return (result);
}

int	main(void)
{
	int	temp;
	int	iter;

	scanf("%d", &iter);
	temp = 0;
	for (int i = 0; i < iter; i++)
	{
		scanf("%d", &temp);
		if (temp != 0)
			push(temp);
		else
			pop();
	}
	printf("%d\n", sum());
	return (0);
}
