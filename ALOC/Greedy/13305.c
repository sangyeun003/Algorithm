// 명제: 현재 주유소보다 뒤에 있는 주유소 중 더 저렴한 곳이 나타날 때까지 현재 주유소 가격으로 주유를 하면 최적!
#include	<stdio.h>

int	main(void)
{
	int	n;
	long long	road[100000];
	long long	station[100000];
	long long	min_fuel;
	long long	cost;

	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
		scanf("%lld", &road[i]);
	for (int i = 0; i < n; i++)
		scanf("%lld", &station[i]);
	min_fuel = station[0];
	cost = 0;
	for (int i = 0; i < n - 1; i++)
	{
		if (min_fuel > station[i])
			min_fuel = station[i];
		cost += min_fuel * road[i];
		// printf("min: %lld, cost: %lld\n", min_fuel, cost);
	}
	printf("%lld\n", cost);
	return (0);
}
