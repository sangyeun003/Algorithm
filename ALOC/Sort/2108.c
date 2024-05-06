#include	<stdio.h>

// 출현 횟수의 max와 그 max값을 갖는 것의 개수(최빈값이 여러 개인지 확인)
void	find_max_and_num(int max_and_num[2], int count[8001])
{
	max_and_num[0] = 0;
	max_and_num[1] = 0;
	for (int i = 0; i < 8001; i++)
	{
		if (count[i] > max_and_num[0])
		{
			max_and_num[0] = count[i];
			max_and_num[1] = 1;
		}
		else if (count[i] == max_and_num[0])
			max_and_num[1]++;
	}
}

int	main(void)
{
	int	n;
	int	num[500000];
	int	count[8001] = {0};
	int	sum;
	int	freq;
	int	index;
	int	max_and_num[2];

	scanf("%d", &n);
	sum = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
		sum += num[i];
		count[num[i] + 4000]++;
	}
	// 최빈값 찾기
	find_max_and_num(max_and_num, count);
	if (max_and_num[1] > 1)	// 최빈값이 여러 개인 경우
	{
		for (int i = 0; i < 8001; i++)
		{
			if (count[i] == max_and_num[0])
			{
				i++;
				while (count[i] != max_and_num[0])	// 2번째로 작은 최빈값 찾기
					i++;
				freq = i - 4000;
				break ;
			}
		}
	}
	else	// 최빈값이 1개인 경우
	{
		for (int i = 0; i < 8001; i++)
		{
			if (count[i] == max_and_num[0])
			{
				freq = i - 4000;
				break ;
			}
		}
	}
	// 정렬 관련
	index = 0;
	for (int i = 0; i < 8001; i++)
	{
		while (count[i] > 0)
		{
			num[index] = i - 4000;
			count[i]--;
			index++;
		}
	}
	// 반올림 처리(int끼리 연산하면 내림 처리됨)
	if (sum >= 0)
		printf("%d\n", (int)((float)sum / n + 0.5));
	else
		printf("%d\n", (int)((float)sum / n - 0.5));
	printf("%d\n", num[n / 2]);
	printf("%d\n", freq);
	printf("%d\n", num[n - 1] - num[0]);
	return (0);
}
