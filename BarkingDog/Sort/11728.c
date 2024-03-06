#include	<stdio.h>

int	main(void)
{
	int	n;
	int	m;
	int	a[1000000];
	int	b[1000000];
	// 용량 많아서 그런지 segfault남. 20000으로 하면 돌아감. 백준 채점기는 맞음
	int	result[2000000];
	int	a_idx;
	int	b_idx;

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < m; i++)
		scanf("%d", &b[i]);
	a_idx = 0;
	b_idx = 0;
	for (int i = 0; i < n + m; i++)
	{
		if (a_idx < n && b_idx < m)
		{
			if (a[a_idx] < b[b_idx])
			{
				result[i] = a[a_idx];
				a_idx++;
			}
			else
			{
				result[i] = b[b_idx];
				b_idx++;
			}
		}
		else if (a_idx < n)
		{
			result[i] = a[a_idx];
			a_idx++;
		}
		else if (b_idx < m)
		{
			result[i] = b[b_idx];
			b_idx++;
		}
		printf("%d ", result[i]);
	}
	return (0);
}
