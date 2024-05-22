#include	<stdio.h>
#include	<stdlib.h>

int	n;
int	a[100000];

int	binary_search(int i)
{
	int	start;
	int	mid;
	int	end;

	start = 0;
	end = n - 1;
	while (start <= end)
	{
		mid = (start + end) / 2;
		// printf("start: %d, mid:%d, end: %d\n", start, mid, end);
		if (a[mid] == i)
			return (1);
		else if (a[mid] < i)
			start = mid + 1;
		else
			end = mid - 1;
	}
	return (0);
}

void	insertion_sort(void)
{
	for (int i = 1; i < n; i++)
	{
		int	j;
		int	key;

		key = a[i];
		for (j = i - 1; j >= 0 && key < a[j]; j--)
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = key;
	}
}

int	compare(const void *a, const void *b)
{
	// return (*(int*)a - *(int*)b);	// 범위가 -2^31~2^31인데, a-b가 2^32가 될 수 있어서 int로 표현 안될 수 있음.
	if (*(int*)a < *(int*)b)
		return (-1);
	else if (*(int*)a > *(int*)b)
		return (1);
	return (0);
}

int	main(void)
{
	int	m;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	// insertion_sort();	// 시간 초과
	qsort(a, n, sizeof(int), compare);
	// for (int i = 0; i < n; i++)
	// 	printf("%d ", a[i]);
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int	tmp;

		scanf("%d", &tmp);
		printf("%d\n", binary_search(tmp));
	}
	return (0);
}
