#include	<stdio.h>

int	is_group(char *s)
{
	int	alpha[27] = {0};

	for (int i = 0; s[i]; i++)
	{
		if (i == 0)
			alpha[s[i] - 'a' + 1] = 1;
		else if (s[i - 1] != s[i] && alpha[s[i] - 'a' + 1] != 0)
			return (0);
		else
			alpha[s[i] - 'a' + 1] = 1;
	}
	return (1);
}

int	main(void)
{
	int		n;
	int		result;
	char	word[101];

	scanf("%d", &n);
	result = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%s", word);
		getchar();
		if (is_group(word))
			result++;
	}
	printf("%d\n", result);
	return (0);
}
