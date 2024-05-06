#include	<stdio.h>

int	main(void)
{
	int	n;
	int	p[1000];
	int	temp;
	int	result;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &p[i]);
	// 선택 정렬
	for (int i = 0; i < n - 1; i++)
	{
		// 최소값 찾아서 swap
		for (int j = i + 1; j < n; j++)
		{
			if (p[i] > p[j])
			{
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
	result = 0;
	for (int i = 0; i < n; i++)
		result += p[i] * (n - i);
	printf("%d\n", result);
	return (0);
}
