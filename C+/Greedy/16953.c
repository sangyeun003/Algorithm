// 명제: b에서부터, b가 2로 나눠지면 2로 나누고, 1로 끝나면 10으로 나누면서 count를 세면 그것이 최소 횟수일 것이다!
#include	<stdio.h>

int	main(void)
{
	int	a;
	int	b;
	int	count;

	scanf("%d %d", &a, &b);
	count = 0;
	while (a < b)
	{
		if (b % 2 == 0)
			b /= 2;
		else if (b % 10 == 1)
			b /= 10;
		else
			break ;
		count++;
	}
	if (a == b)
		printf("%d\n", count + 1);
	else
		printf("-1\n");
	return (0);
}
