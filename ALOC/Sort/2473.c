// 투 포인터 or 이진 탐색
#include	<stdio.h>

long	sorted[5000];

void	merge(long x[], int left, int mid, int right)
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

void	merge_sort(long x[], int left, int right)
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

long	labs(long n)
{
	return (n > 0 ? n : n * (-1));
}

int	main(void)
{
	int		n;
	long	liq[5000];
	int		start;
	int		end;
	long	min;
	long	sum;
	int		ans_idx[3];

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%ld", &liq[i]);
	merge_sort(liq, 0, n - 1);
	min = liq[0] + liq[1] + liq[n - 1];
	ans_idx[0] = 0;
	ans_idx[1] = 1;
	ans_idx[2] = n - 1;
	for (int i = 0; i < n - 2; i++)
	{
		start = i + 1;
		end = n - 1;
		while (start < end)
		{
			sum = liq[i] + liq[start] + liq[end];
			if (labs(sum) < labs(min))
			{
				min = sum;
				ans_idx[0] = i;
				ans_idx[1] = start;
				ans_idx[2] = end;
			}
			if (sum > 0)
				end--;
			else if (sum < 0)
				start++;
			else
				break ;
		}
	}
	printf("%ld %ld %ld\n", liq[ans_idx[0]], liq[ans_idx[1]], liq[ans_idx[2]]);
	return (0);
}
