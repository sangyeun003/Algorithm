// start ~ end까지 중에서 max를 계속 선택
#include	<stdio.h>

int	main(void)
{
	int		n;
	int		k;
	char	num[500001];
	char	result[500001];
	int		start;
	int		end;
	int		max;

	scanf("%d %d", &n, &k);
	scanf("%s", num);
	start = 0;
	end = (n - 1) - (n - k - 1);
	while (end < n)
	{
		// printf("start: %d, end: %d\n", start, end);
		max = num[start];
		for (int i = start; i <= end; i++)
		{
			if (max < num[i])
			{
				max = num[i];
				start = i;
				// 시간초과 나다가 아래 두 줄 예외처리 했더니 맞음
				if (num[i] == '9')
					break ;
			}
		}
		result[end - ((n - 1) - (n - k - 1))] = max;
		start = start + 1;
		end++;
	}
	printf("%s\n", result);
	return (0);
}
