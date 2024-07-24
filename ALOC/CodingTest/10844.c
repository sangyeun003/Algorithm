#include	<stdio.h>

int	t[101][10];

int	main(void)
{
	int	n;
	int	result;

	scanf("%d", &n);
	if (n == 1)
	{
		printf("9\n");
		return (0);
	}
	// 초기화
	for (int i = 0; i <= 9; i++)
		t[1][i] = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (j - 1 >= 0)
				t[i][j] = (t[i][j] + t[i - 1][j - 1]) % 1000000000;
			if (j + 1 <= 9)
				t[i][j] = (t[i][j] + t[i - 1][j + 1]) % 1000000000;
		}
	}
	result = 0;
	for (int i = 1; i <= 9; i++)
		result = (result + t[n][i]) % 1000000000;
	printf("%d\n", result);
	return (0);
}
