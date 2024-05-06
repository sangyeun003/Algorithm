// 1. 테이블 정의 -> length[i][0]: 연속해서 증가하는 최대 길이, length[i][1]: 연속해서 감소하는 최대 길이
// 2. 점화식 찾기
// 3. 초기값 정하기
#include	<stdio.h>

int	find_max(int arr[100001][2], int n)
{
	int	max;

	max = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (arr[j][i] > max)
				max = arr[j][i];
		}
	}
	return (max);
}

int	main(void)
{
	int	n;
	int	num[100001];
	// length[i][0]: 증가 방향
	// length[i][1]: 감소 방향
	int	length[100001][2];

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &num[i]);
	length[0][0] = 0;
	length[0][1] = 0;
	length[1][0] = 1;
	length[1][1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (num[i] > num[i - 1])
		{
			length[i][0] = length[i - 1][0] + 1;
			length[i][1] = 1;
		}
		else if (num[i] < num[i - 1])	// num[i] < num[i - 1]
		{
			length[i][1] = length[i - 1][1] + 1;
			length[i][0] = 1;
		}
		else
		{
			length[i][0] = length[i - 1][0] + 1;
			length[i][1] = length[i - 1][1] + 1;
		}
	}
	printf("%d\n", find_max(length, n));
	return (0);
}
