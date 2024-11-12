#include	<stdio.h>

int	temp[100000][2];

void	merge(int rank[][2], int start, int mid, int end)
{
	int	i;
	int	j;
	int	k;

	i = start;
	j = mid + 1;
	k = start;
	while (i <= mid && j <= end)
	{
		if (rank[i][0] < rank[j][0])
		{
			temp[k][0] = rank[i][0];
			temp[k][1] = rank[i][1];
			i++;
		}
		else
		{
			temp[k][0] = rank[j][0];
			temp[k][1] = rank[j][1];
			j++;
		}
		k++;
	}
	while (i <= mid)
	{
		temp[k][0] = rank[i][0];
		temp[k][1] = rank[i][1];
		i++;
		k++;
	}
	while (j <= end)
	{
		temp[k][0] = rank[j][0];
		temp[k][1] = rank[j][1];
		j++;
		k++;
	}
	while (start <= end)
	{
		rank[start][0] = temp[start][0];
		rank[start][1] = temp[start][1];
		start++;
	}
}

void	merge_sort(int rank[][2], int start, int end)
{
	int	mid;

	if (start >= end)
		return ;
	else
	{
		mid = (start + end) / 2;
		merge_sort(rank, start, mid);
		merge_sort(rank, mid + 1, end);
		merge(rank, start, mid, end);
	}
}

int	main(void)
{
	int	t;
	int	n;
	int	rank[100000][2];
	int	result;
	int	min;

	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d", &n);
		for (int j = 0; j < n; j++)
			scanf("%d %d", &rank[j][0], &rank[j][1]);
		merge_sort(rank, 0, n - 1);
		result = 1;
		min = rank[0][1];
		for (int j = 1; j < n; j++)
		{
			if (rank[j][1] < min)
			{
				result++;
				min = rank[j][1];
			}
		}
		printf("%d\n", result);
	}
	return (0);
}
