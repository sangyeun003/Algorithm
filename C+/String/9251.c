// 알고리즘이 이해가 안됨
#include	<stdio.h>
#include	<string.h>

int	max(int a, int b)
{
	return (a > b ? a : b);
}

int	lcs(char *s1, char *s2)
{
	int	dp[1001][1001] = {0};
	int	l1;
	int	l2;
	int	i;
	int	j;

	l1 = strlen(s1);
	l2 = strlen(s2);
	for (i = 0; i <= l1; i++)
	{
		for (j = 0; j <= l2; j++)
		{
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else if (s1[i - 1] != s2[j - 1])
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			else	// s1[i - 1] == s2[j - 1]
				dp[i][j] = dp[i - 1][j - 1] + 1;
		}
	}
	return (dp[l1][l2]);
}

int	main(void)
{
	char	s1[1001];
	char	s2[1001];

	scanf("%s", s1);
	scanf("%s", s2);
	printf("%d\n", lcs(s1, s2));
	return (0);
}
