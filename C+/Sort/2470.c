// 투 포인터 or 이진 탐색
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

// int	main(void)
// {
// 	int	n;
// 	int	liq[100000];
// 	int	start;
// 	int	end;
// 	int	min;
// 	int	sum;
// 	int	ans_idx[2];

// 	scanf("%d", &n);
// 	for (int i = 0; i < n; i++)
// 		scanf("%d", &liq[i]);
// 	merge_sort(liq, 0, n - 1);
// 	start = 0;
// 	end = n - 1;
// 	min = liq[start] + liq[end];
// 	sum = min;
// 	ans_idx[0] = start;
// 	ans_idx[1] = end;
// 	while (start < end)
// 	{
// 		sum = liq[start] + liq[end];
// 		if (abs(sum) < abs(min))
// 		{
// 			min = sum;
// 			ans_idx[0] = start;
// 			ans_idx[1] = end;
// 		}
// 		if (sum > 0)
// 			end--;
// 		else if (sum < 0)
// 			start++;
// 		else
// 			break ;
// 	}
// 	printf("%d %d\n", liq[ans_idx[0]], liq[ans_idx[1]]);
// 	return (0);
// }

// 이진 탐색 풀이
// 현재 수 * (-1)과 제일 가까운 수를 탐색

int	binary_search(int liq[], int start, int end, int target, int closest)
{
	int	mid;

	if (start > end)
		return (closest);
	mid = (start + end) / 2;
	if (liq[mid] == target)
		return (mid);
	else
	{
		if (abs(liq[mid] - target) < abs(liq[closest] - target))
			closest = mid;
		if (target < liq[mid])
			return (binary_search(liq, start, mid - 1, target, closest));
		else
			return (binary_search(liq, mid + 1, end, target, closest));
	}
}

int	main(void)
{
	int	n;
	int	liq[100000];
	int	min;
	int	sum;
	int	closest;
	int	ans_idx[2];

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &liq[i]);
	merge_sort(liq, 0, n - 1);
	// for (int i = 0; i < n; i++)
	// 	printf("%d ", liq[i]);
	// printf("\n");
	ans_idx[0] = 0;
	ans_idx[1] = n - 1;
	min = liq[0] + liq[n - 1];
	sum = min;
	for (int i = 0; i < n; i++)
	{
		closest = binary_search(liq, 0, n - 1, (-1) * liq[i], i);
		if (closest == i)
		{
			if (i > 0 && i < n - 1)
			{
				if (abs(liq[i] + liq[i + 1]) < abs(liq[i - 1] + liq[i]))
					closest = i + 1;
				else
					closest = i - 1;
			}
			else if (i == 0)
				closest = i + 1;
			else	// i == n - 1
				closest = i - 1;
		}
		// printf("closest: %d\n", liq[closest]);
		sum = liq[i] + liq[closest];
		if (abs(sum) < abs(min))
		{
			min = sum;
			ans_idx[0] = i;
			ans_idx[1] = closest;
		}
	}
	printf("%d %d\n", liq[ans_idx[0]], liq[ans_idx[1]]);
	return (0);
}
