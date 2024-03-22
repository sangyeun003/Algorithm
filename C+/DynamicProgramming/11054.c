// inc[i] = a[i]로 끝나는 수열 중 가장 긴 증가하는 부분 수열
// dec[i] = a[i]로 시작하는 수열 중 가장 긴 감소하는 부분 수열
// bito[i] = a[i]가 증감 교차 지점인 수열 중 가장 긴 바이토닉 부분 수열
// n번째 항부터 채움
#include	<stdio.h>

int	main(void)
{
	int	n;
	int	a[1001];
	int	inc[1001];
	int	dec[1001];
	int	bito[1001];
	int	max;
	int	result;

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	// inc 만들기
	inc[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		max = 0;
		for (int j = 1; j < i; j++)
		{
			if (a[i] > a[j] && inc[j] > max)
				max = inc[j];
		}
		inc[i] = max + 1;
	}
	// dec 만들기
	dec[n] = 1;
	for (int i = n - 1; i >= 1; i--)
	{
		max = 0;
		for (int j = i + 1; j <= n; j++)
		{
			if (a[i] > a[j] && dec[j] > max)
				max = dec[j];
		}
		dec[i] = max + 1;
	}
	result = 1;	// 길이 1일 때 답 1
	for (int i = 1; i <= n - 1; i++)
	{
		max = dec[i] - 1;	// 최고값이 겹칠 때
		for (int j = i + 1; j <= n; j++)
		{
			if (dec[j] > max)
			{
				if (a[i] == a[j])	// 바이토닉 수열 안에 같은 값 들어가면 안됨
					max = dec[j] - 1;
				else
					max = dec[j];
			}
		}
		bito[i] = inc[i] + max;
		if (bito[i] > result)
			result = bito[i];
	}
	printf("%d\n", result);
	return (0);
}
