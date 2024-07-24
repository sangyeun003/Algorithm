#include	<stdio.h>

int	main(void)
{
	int		alpha[27] = {0,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10};
	char	s[16];
	int		result;
	
	scanf("%s", s);
	result = 0;
	for (int i = 0; s[i]; i++)
	{
		// printf("%d, %c, %d\n", s[i] - 'A' + 1, s[i], alpha[s[i] - 'A' + 1]);
		result += alpha[s[i] - 'A' + 1];
	}
	printf("%d\n", result);
	return (0);
}
