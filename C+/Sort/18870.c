// 정렬을 하면서 자리를 바꿔줄 때 index의 자리도 같이 바꿔주면 됨.
#include	<stdio.h>

// 정렬된 배열을 담을 공간
int	sorted[1000000];

int	search_index(int *temp, int num, int start, int end)
{
	int	mid;

	mid = (start + end) / 2;
	if (temp[mid] == num)
		return (mid);
	else if (temp[mid] < num)
		return (search_index(temp, num, mid + 1, end));
	else
		return (search_index(temp, num, start, mid - 1));
}

void	merge(int x[], int left, int mid, int right)
{
	int	i;
	int	j;
	int	k;

	i = left;
	j = mid + 1;
	k = left;
	// 두 배열 merge
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
	// 둘 중 한 배열만 저장이 끝난 경우
	// 남은 숫자들을 넣어줘야 함
	while (i <= mid)
	{
		sorted[k] = x[i];
		i++;
		k++;
	}
	while (j <= right)
	{
		sorted[k] = x[j];
		j++;
		k++;
	}
	// sorted에 있는 내용을 x 배열에 복사
	// 정렬된 부분끼리 합치기 때문에 이걸 안해주면 merge할 때 정렬이 안됨
	for (int l = left; l <= right; l++)
		x[l] = sorted[l];
}

void	merge_sort(int x[], int left, int right)
{
	int	mid;

	if (left >= right)
		return ;
	else
	{
		mid = (left + right) / 2;
		merge_sort(x, left, mid);
		merge_sort(x, mid + 1, right);
		merge(x, left, mid, right);
	}
}

void	quick_sort(int x[], int left, int right)
{
	int	pivot_index;
	int	low;
	int	high;
	int	temp;

	if (left >= right)
		return ;
	// partition
	pivot_index = left;
	low = left + 1;
	high = right;
	while (low <= high)
	{
		// x[low] <= x[pivot_index] 여기에 등호 하나 넣었더니 잘되네?
		// 중복되는 수 없으면 등호 없어도 잘됨 
		while (low <= high && x[low] <= x[pivot_index])
			low++;
		while (low <= high && x[high] > x[pivot_index])
			high--;
		// swap
		if (low < high)
		{
			temp = x[low];
			x[low] = x[high];
			x[high] = temp;
		}
	}
	temp = x[high];
	x[high] = x[pivot_index];
	x[pivot_index] = temp;
	quick_sort(x, left, high - 1);
	quick_sort(x, high + 1, right);
}

int	main(void)
{
	int	n;
	int	x[10000];
	int	temp[10000];
	int	not_dup[10000];	// 중복 제거
	int	index;	// 중복 제거한 후 숫자의 개수를 저장

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x[i]);
		temp[i] = x[i];
	}
	// 정렬
	// 방법1. merge sort
	merge_sort(temp, 0, n - 1);
	// 방법2. quick sort
	// quick_sort(temp, 0, n - 1);
	// for (int i = 0; i < n; i++)
	// 	printf("%d ", temp[i]);
	// printf("\n");
	// for (int i = 0; i < n; i++)
	// 	printf("%d ", sorted[i]);
	// printf("\n");

	// 중복 제거해서 temp에 저장
	// 용량을 줄이기 위해 이중 반복문으로도 중복 제거 가능할 것 같지만, 시간 복잡도가 증가
	not_dup[0] = temp[0];
	index = 0;	// 새로 저장해야할 곳의 index
	for (int i = 1; i < n; i++)
	{
		if (not_dup[index] != temp[i])
		{
			index++;
			not_dup[index] = temp[i];
		}
	}
	// 탐색
	for (int i = 0; i < n; i++)
		printf("%d ", search_index(not_dup, x[i], 0, index));
	return (0);
}
