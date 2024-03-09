#include	<stdio.h>

int	abs(int n)
{
	return (n >= 0 ? n : n * (-1));
}

void	choose()
{

}

int	main(void)
{
	int	map[50][50];
	int	n;
	int	m;
	int	house_num;
	int	chicken_num;
	int	total;

	scanf("%d %d", &n, &m);
	house_num = 0;
	chicken_num = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1)
				house_num++;
			else if (map[i][j] == 2)
				chicken_num++;
		}
	}
	total = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 1)
				total
		}
	}
	return (0);
}
