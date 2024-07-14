// char	map[50][50]이 아니라, char map[51][51]로 만들었어야 함
#include	<stdio.h>

int		n;
char	map[51][51];

int	row_max_continuous()	// 현재 상태 기준 행 중에서 가장 긴 연속 알파벳 길이
{
	int	max_cont;
	int	len;

	max_cont = 0;
	for (int i = 0; i < n; i++)
	{
		len = 1;
		for (int j = 1; j < n; j++)
		{
			if (map[i][j - 1] == map[i][j])
				len++;
			else
			{
				if (max_cont < len)
					max_cont = len;
				len = 1;
			}
		}
		if (max_cont < len)
			max_cont = len;
	}
	return max_cont;
}

int	col_max_continuous()	// 현재 상태 기준 열 중에서 가장 긴 연속 알파벳 길이
{
	int	max_cont;
	int	len;

	max_cont = 0;
	for (int i = 0; i < n; i++)		// 열
	{
		len = 1;
		for (int j = 1; j < n; j++)	// 행
		{
			if (map[j - 1][i] == map[j][i])
				len++;
			else
			{
				if (max_cont < len)
					max_cont = len;
				len = 1;
			}
		}
		if (max_cont < len)
			max_cont = len;
	}
	return max_cont;
}

void	swap(int x1, int y1, int x2, int y2)
{
	char	temp;

	temp = map[x1][y1];
	map[x1][y1] = map[x2][y2];
	map[x2][y2] = temp;
}

int	main(void)
{
	int	eatable_candy;
	int	max;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%s", map[i]);
	max = 0;
	// printf("row_max: %d, col_max: %d\n", row_max_continuous(), col_max_continuous());
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j + 1 < n)
			{
				swap(i, j, i, j + 1);
				eatable_candy = row_max_continuous();
				if (max < eatable_candy)
					max = eatable_candy;
				eatable_candy = col_max_continuous();
				if (max < eatable_candy)
					max = eatable_candy;
				swap(i, j, i, j + 1);
			}
			if (i + 1 < n)
			{
				swap(i, j, i + 1, j);
				eatable_candy = row_max_continuous();
				if (max < eatable_candy)
					max = eatable_candy;
				eatable_candy = col_max_continuous();
				if (max < eatable_candy)
					max = eatable_candy;
				swap(i, j, i + 1, j);
			}
		}
	}
	printf("%d\n", max);
	return (0);
}
