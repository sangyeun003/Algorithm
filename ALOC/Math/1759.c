#include	<stdio.h>

int		l;
int		c;
char	alpha[16];

void	dfs(int start, int depth, int vowel_flag)
{
	
}

int	main(void)
{
	char	alpha[16];

	scanf("%d %d", &l, &c);
	for (int i = 0; i < c; i++)
	{
		scanf(" %c", &alpha[i]);
	}
	printf("%s\n", alpha);
	sort(alpha);
	for (int start = 0; start < c - l; start++)
		dfs(start, 0, 0);
	return (0);
}
