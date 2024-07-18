// t[i]: i번째 수가 반드시 포함될 때, 0번째부터의 합
#include	<stdio.h>

int	max(int a, int b)
{
	return a > b ? a : b;
}

int	main(void)
{
	int	n;
	int	num[1000000];
	int	t[1000000];
	int	result;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);
	t[0] = num[0];
	result = t[0];
	// 방법1
	// for (int i = 1; i < n; i++)
	// {
	// 	t[i] = max(num[i], t[i - 1] + num[i]);
	// 	if (t[i] > result)
	// 		result = t[i];
	// }
	// 방법2
	for (int i = 1; i < n; i++)
	{
		if (t[i - 1] < 0)
			t[i] = num[i];
		else
			t[i] = num[i] + t[i - 1];
		if (t[i] > result)
			result = t[i];
	}
	printf("%d\n", result);
	return (0);
}
