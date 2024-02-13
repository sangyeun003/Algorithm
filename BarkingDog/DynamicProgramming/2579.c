#include	<stdio.h>

int	score[301];

int	max(int a, int b)
{
	return (a > b ? a : b);
}

// 내 방법
// int	total[301];

// int	main(void)
// {
// 	int	n;

// 	scanf("%d", &n);
// 	for (int i = 1; i <= n; i++)
// 		scanf("%d", &score[i]);
// 	total[1] = score[1];
// 	total[2] = score[1] + score[2];
// 	for (int i = 3; i <= n; i++)
// 		total[i] = max(total[i - 2], total[i - 3] + score[i - 1]) + score[i];
// 	printf("%d\n", total[n]);
// 	return (0);
// }

// 유튜브 방법1
// 행렬의 행은 total 점수, 열은 연속해서 밟은 계단의 수
// int	d[301][3];

// int	main(void)
// {
// 	int	n;

// 	scanf("%d", &n);
// 	for (int i = 1; i <= n; i++)
// 		scanf("%d", &score[i]);
// 	d[1][1] = score[1];
// 	d[2][1] = score[2];
// 	d[2][2] = score[1] + score[2];
// 	for (int i = 3; i <= n; i++)
// 	{
// 		d[i][1] = max(d[i - 2][1], d[i - 2][2]) + score[i];
// 		d[i][2] = d[i - 1][1] + score[i];
// 	}
// 	printf("%d\n", max(d[n][1], d[n][2]));
// 	return (0);
// }

// 유튜브 방법2
// i번째 계단까지 올라섰을 때 밟지 않을 계단의 합을 최소화
// 단, i번째 계단은 반드시 밟지 않을 계단으로 선택

// 미완성. 이해 못함.

// int	min_total[301];

// int min(int a, int b)
// {
//     return (a < b ? a : b);
// }

// int	main(void)
// {
// 	int	n;

// 	scanf("%d", &n);
// 	for (int i = 1; i <= n; i++)
// 		scanf("%d", &score[i]);
// 	min_total[1] = score[1];
// 	min_total[2] = score[2];
// 	min_total[3] = score[3];
// 	for (int i = 3; i <= n; i++)
// 		min_total[i] = min(min_total[i - 2], min_total[i - 3] + score[i - 1]) + score[i];
// 	printf("%d\n", min_total[n]);
// 	return (0);
// }
