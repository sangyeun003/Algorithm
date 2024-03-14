#include	<stdio.h>

void	dfs(int *arr, int n, int s, int start, int sum, int *count)
{
	if (start == n)
		return ;
	sum += arr[start];
	printf("start: %d, sum: %d\n", start, sum);
	if (sum == s)
		(*count)++;
	for (int i = start + 1; i < n; i++)
		dfs(arr, n, s, i, sum, count);
}

int	main(void)
{
	int	n;
	int	s;
	int	arr[1000000];
	int	sum;
	int	count;

	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	count = 0;
	for (int start = 0; start < n; start++)	// 합칠 수의 개수
		dfs(arr, n, s, start, 0, &count);
	printf("%d\n", count);
	return (0);
}
