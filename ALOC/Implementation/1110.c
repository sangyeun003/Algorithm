#include	<stdio.h>

int	main(void)
{
	int	n;
	int	temp;
	int	cycle;
	int	new_num;

	scanf("%d", &n);
	new_num = n;
	for (cycle = 1; ; cycle++)
	{
		temp = new_num / 10 + new_num % 10;
		new_num = new_num % 10 * 10 + temp % 10;
		if (new_num == n)
		{
			printf("%d\n", cycle);
			return (0);
		} 
	}
	return (0);
}
