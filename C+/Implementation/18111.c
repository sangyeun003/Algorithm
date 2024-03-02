#include	<stdio.h>

int	main(void)
{
	int	map[250000];
	int	n;
	int	m;
	int	b;
	int	residual;	// 평균보다 높은 것 개수 저장
	int	to_supplement;	// 평균보다 낮은 것 개수 저장
	int	min_time;
	int	height;

	scanf("%d %d %d", &n, &m, &b);
	for (int i = 0; i < n * m; i++)
		scanf("%d", &map[i]);
	min_time = 64000000;
	height = 0;
	for (int h = 0; h <= 256; h++)
	{
		residual = 0;
		to_supplement = 0;
		for (int i = 0; i < n * m; i++)
		{
			if (map[i] - h > 0)
				residual += map[i] - h;
			else
				to_supplement += h - map[i];
		}
		if (b + residual >= to_supplement)
		{
			if (2 * residual + to_supplement < min_time)
			{
				min_time = 2 * residual + to_supplement;
				height = h;
			}
			else if (2 * residual + to_supplement == min_time && h > height)
				height = h;
		}
	}
	printf("%d %d\n", min_time, height);
	return (0);
}
