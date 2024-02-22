#include	<stdio.h>

int	is_empty(char *s)
{
	return (s[0] == 0);
}

void	push(char *s)
{
	int	i;

	for (i = 0; s[i]; i++);
	s[i] = '(';
	s[i + 1] = 0;
}

int	pop(char *s)
{
	int	i;

	if (is_empty(s))
		return (-1);
	for (i = 0; s[i]; i++);
	s[i - 1] = 0;
	return (1);
}

int	VPS(char *s)
{
	char	stack[51] = {0};

	for (int i = 0; s[i]; i++)
	{
		if (s[i] == '(')
			push(stack);
		else
		{
			if (pop(stack) == -1)
				return (0);
		}
	}
	if (!is_empty(stack))
		return (0);
	return (1);
}

int	main(void)
{
	int		t;
	char	s[51];

	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%s", s);
		getchar();
		if (VPS(s))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return (0);
}
