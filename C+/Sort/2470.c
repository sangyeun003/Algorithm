#include	<stdio.h>

int	sorted[100000];

void	merge(int x[], int left, int mid, int right)
{
	int	i;
	int	j;
	int	k;

	i = left;
	j = mid + 1;
	k = left;
	while (i <= mid && j <= right)
	{
		if (x[i] < x[j])
		{
			sorted[k] = x[i];
			i++;
		}
		else
		{
			sorted[k] = x[j];
			j++;
		}
		k++;
	}
	while (i <= mid)
	{
		sorted[k] = x[i];
		k++;
		i++;
	}
	while (j <= right)
	{
		sorted[k] = x[j];
		k++;
		j++;
	}
	while (left <= right)
	{
		x[left] = sorted[left];
		left++;
	}
}

void	merge_sort(int x[], int left, int right)
{
	int	mid;

	if (left >= right)
		return ;
	else
	{
		mid = (left + right) >> 1; // (left + right) / 2
		merge_sort(x, left, mid);
		merge_sort(x, mid + 1, right);
		merge(x, left, mid, right);
	}
}

int	abs(int n)
{
	return (n > 0 ? n : n * (-1));
}

int	main(void)
{
	int	n;
	int	liq[100000];
	int	start;
	int	end;
	int	min;
	int	sum;
	int	ans_idx[2];

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &liq[i]);
	merge_sort(liq, 0, n - 1);
	start = 0;
	end = n - 1;
	min = liq[start] + liq[end];
	sum = min;
	ans_idx[0] = start;
	ans_idx[1] = end;
	while (start < end)
	{
		sum = liq[start] + liq[end];
		if (abs(sum) < abs(min))
		{
			min = sum;
			ans_idx[0] = start;
			ans_idx[1] = end;
		}
		if (sum > 0)
			end--;
		else
			start++;
	}
	printf("%d %d\n", liq[ans_idx[0]], liq[ans_idx[1]]);
	return (0);
}
