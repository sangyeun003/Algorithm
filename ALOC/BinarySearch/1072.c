#include	<stdio.h>

int	main(void)
{
	long	x;
	long	y;
	long	z;
	long	count;
	long	left;
	long	right;
	int		mid;

	scanf("%ld %ld", &x, &y);
	z = 100 * y / x;
	if (z >= 99)	// 현재 승률이 99나 100이라면 승률 변할 수 없음.
	{
		printf("-1\n");
		return (0);
	}
	left = 1;
	right = x;	// 최악의 경우 x만큼 게임을 더 해야 확률 변함. ex) 100 98
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (100 * (y + mid) / (x + mid) > z)	// mid - x: 게임 더 한 횟수
		{
			count = mid;	// 답 저장
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	// for (count = 1; 100 * (y + count) / (x + count) <= z; count++);	// 시간 초과.
	printf("%ld\n", count);
	return (0);
}
