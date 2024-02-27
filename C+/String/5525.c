#include	<stdio.h>
#include	<string.h>

int	main(void)
{
	int		n;
	int		m;
	int		result;
	char	s[1000001];
	char	ioi[1000001];

	scanf("%d", &n);
	scanf("%d", &m);
	scanf("%s", s);

	for (int i = 0; i < 2 * n + 1; i++)
		if (i % 2 == 0)
			ioi[i] = 'I';
		else
			ioi[i] = 'O';
	result = 0;
	// s[i + 2 * n + 1 - 1]
	for (int i = 0; s[i + 2 * n + 1 - 1]; i++)
	{
		// printf("%d\n", strncmp(&s[i], ioi, 2 * n + 1));
		if (strncmp(s + i, ioi, 2 * n) == 0)
			result++;
	}
	printf("%d\n", result);
	return (0);
}
