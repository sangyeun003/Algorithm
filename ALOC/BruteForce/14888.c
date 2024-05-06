#include	<stdio.h>

void	dfs(int a[], int idx, int sum, int now_oper, int add, int sub, int mul, int div, int *max, int *min)
{
	if (sum > *max && (add == 0 && sub == 0 && mul == 0 && div == 0))
		*max = sum;
	if (sum < *min && (add == 0 && sub == 0 && mul == 0 && div == 0))
		*min = sum;
	// 종료 조건
	if (now_oper == 1 && add == 0)
		return ;
	if (now_oper == 2 && sub == 0)
		return ;
	if (now_oper == 3 && mul == 0)
		return ;
	if (now_oper == 4 && div == 0)
		return ;
	// 연산
	if (now_oper == 1)
	{
		sum += a[idx];
		add--;
	}
	else if (now_oper == 2)
	{
		sum -= a[idx];
		sub--;
	}
	else if (now_oper == 3)
	{
		sum *= a[idx];
		mul--;
	}
	else if (now_oper == 4)
	{
		sum /= a[idx];
		div--;
	}
	for (int i = 1; i <= 4; i++)
		dfs(a, idx + 1, sum, i, add, sub, mul, div, max, min);
}

int	main(void)
{
	int n;
	int	a[11];
	int	oper[4];
	int	max;
	int	min;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < 4; i++)
		scanf("%d", &oper[i]);
	max = -1000000000;
	min = 1000000000;
	for (int i = 1; i <= 4; i++)
		dfs(a, 1, a[0], i, oper[0], oper[1], oper[2], oper[3], &max, &min);
	printf("%d\n%d\n", max, min);
	return (0);
}
