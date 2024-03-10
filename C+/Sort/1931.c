#include	<stdio.h>

void	quick_sort(int time[][2], int start, int end)
{
	int	pivot;
	int	left;
	int	right;
	int	temp;

	if (start >= end)
		return ;
	pivot = start;
	left = start + 1;
	right = end;
	while (left <= right)
	{
		while (left < end && time[left][1] <= time[pivot][1])
			left++;
		while (right > start && time[right][1] >= time[pivot][1])
			right--;
		if (left < right)
		{
			temp = time[left][1];
			time[left][1] = time[right][1];
			time[right][1] = temp;
			temp = time[left][0];
			time[left][0] = time[right][0];
			time[right][0] = temp;
		}
	}
	temp = time[right][1];
	time[right][1] = time[pivot][1];
	time[pivot][1] = temp;
	temp = time[right][0];
	time[right][0] = time[pivot][0];
	time[pivot][0] = temp;
	quick_sort(time, start, right - 1);
	quick_sort(time, right + 1, end);
}

int	temp[100000][2];

void	merge(int time[][2], int start, int mid, int end)
{
	int	i;
	int	j;
	int	k;

	i = start;
	j = mid + 1;
	k = start;
	while (i <= mid && j <= end)
	{
		if (time[i][1] < time[j][1])
		{
			temp[k][0] = time[i][0];
			temp[k][1] = time[i][1];
			i++;
		}
		else if (time[i][1] == time[j][1])
		{
			if (time[i][0] < time[j][0])
			{
				temp[k][0] = time[i][0];
				temp[k][1] = time[i][1];
				i++;
			}
			else
			{
				temp[k][0] = time[j][0];
				temp[k][1] = time[j][1];
				j++;
			}
		}
		else
		{
			temp[k][0] = time[j][0];
			temp[k][1] = time[j][1];
			j++;
		}
		k++;
	}
	while (i <= mid)
	{
		temp[k][0] = time[i][0];
		temp[k][1] = time[i][1];
		i++;
		k++;
	}
	while (j <= end)
	{
		temp[k][0] = time[j][0];
		temp[k][1] = time[j][1];
		j++;
		k++;
	}
	for (int l = start; l <= end; l++)
	{
		time[l][0] = temp[l][0];
		time[l][1] = temp[l][1];
	}
}

void	merge_sort(int time[][2], int start, int end)
{
	int	mid;

	if (start >= end)
		return ;
	mid = (start + end) / 2;
	merge_sort(time, start, mid);
	merge_sort(time, mid + 1, end);
	merge(time, start, mid, end);
	// for (int i = start; i <= end; i++)
	// 	printf("%d %d\n", time[i][0], time[i][1]);
	// printf("\n");
}

int	main(void)
{
	int	n;
	int	time[100000][2];
	int	meet_num;
	int	meeting[2];

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &time[i][0], &time[i][1]);
	// quick_sort(time, 0, n - 1);
	merge_sort(time, 0, n - 1);
	meet_num = 1;
	meeting[0] = time[0][0];
	meeting[1] = time[0][1];
	for (int i = 1; i < n; i++)
	{
		if (time[i][0] >= meeting[1])
		{
			meeting[0] = time[i][0];
			meeting[1] = time[i][1];
			meet_num++;
		}
	}
	printf("%d\n", meet_num);
	return (0);
}
