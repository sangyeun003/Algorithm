#include	<stdio.h>
#include	<string.h>

// 어긋나기 시작한 index를 return
int	my_strncmp(char *s1, char *s2, int n)
{
	int	i;

	for (i = 0; s1[i] && s2[i] && i < n; i++)
	{
		if (s1[i] != s2[i])
			return (i);
	}
	return (0);
}

int	main(void)
{
	int		n;
	int		m;
	int		result;
	char	s[1000001];
	char	ioi[1000001];
	int		diff;

	scanf("%d", &n);
	scanf("%d", &m);
	scanf("%s", s);

	for (int i = 0; i < 2 * n + 1; i++)
		if (i % 2 == 0)
			ioi[i] = 'I';
		else
			ioi[i] = 'O';
	result = 0;
	for (int i = 0; i + 2 * n + 1 - 1 < m; i++)
	{
		// printf("%d\n", strncmp(&s[i], ioi, 2 * n + 1));
		if (s[i] == 'I' && s[i + 1] == 'O' && s[i + 2] == 'I')
		{
			diff = my_strncmp(s + i, ioi, 2 * n + 1);
			if (diff == 0)
			{
				result++;
				i++;
			}
			else
			{
				if (diff % 2 == 0)
					i += diff;
				else
					i += diff - 1;
			}
		}
	}
	printf("%d\n", result);
	return (0);
}
