#include	<stdio.h>

int	main(void)
{
	int	n;
	int	time[100000][2];

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &time[i][0], &time[i][1]);
}