#include	<stdio.h>

int	array[1001];

void	reset_array(void)
{
	for (int i = 1; i < 1001; i++)
		array[i] = 0;
}

void	cycle(void)
{
	int	n;
	int	start;
	int	cycles;

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &array[i]);
	cycles = 0;
	for (int i = 1; i <= n; i++)
	{
		if (array[i] != 0)
		{
			start = i;
			while (start != array[i])
			{
				int	next = array[i];
				array[i] = 0;	// 방문 표시
				i = next;
			}
			array[i] = 0;
			i = start;
			cycles++;
			// printf("%d\n", start);
		}
	}
	printf("%d\n", cycles);
}

int	main(void)
{
	int	t;

	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		reset_array();
		cycle();
	}
	return (0);
}
