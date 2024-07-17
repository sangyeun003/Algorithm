#include	<stdio.h>

int	main(void)
{
	int	n;
	int	t;
	int	ans[12];

	scanf("%d", &t);
	ans[1] = 1;
	ans[2] = 2;
	ans[3] = 4;
	for (int i = 4; i < 11; i++)
		ans[i] = ans[i - 1] + ans[i - 2] + ans[i - 3];
	for (int i = 0; i < t; i++)
	{
		scanf("%d", &n);
		printf("%d\n", ans[n]);
	}
	return (0);
}
