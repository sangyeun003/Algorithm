#include <stdio.h>


int trees[1000000];

int	main(void)
{
	int n;
	int m;
	int	max;
	int	start;
	int	mid;
	int	end;
	int	ans;
	
	scanf("%d %d", &n, &m);
	max = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &trees[i]);
		if (trees[i] > max)
			max = trees[i];
		// printf("%d %d\n", min, max);
	}
	
	start = 0;
	end = max;
	while (start <= end)
	{
		mid = (start + end) / 2;
		long long temp = 0;
		for (int i = 0; i < n; i++)
		{
			if (trees[i] - mid > 0)
				temp += trees[i] - mid;
		}
		// printf("start: %d, mid: %d, end: %d, sum: %lld\n", start, mid, end, temp);
		if (temp >= m)
		{
			ans = mid;
			if (temp == m)
				break ;
			start = mid + 1;
		}
		else
			end = mid - 1;
	}
	printf("%d\n", ans);
	return (0);
}
	