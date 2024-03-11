// 정렬하고 음수 개수가 홀수냐 짝수냐
// 음수는 앞쪽부터 묶기 or 홀수/짝수 판별해서 하기
// 양수는 뒤쪽부터 묶기 or 홀수/짝수 판별해서 하기
// 0 여부 판단
// 음수가 홀수 개 & 0 존재 -> 두개 묶어버리기
#include	<stdio.h>

int	temp[50];

void	merge(int num[], int start, int mid, int end)
{
	int	i;
	int	j;
	int	k;

	i = start;
	j = mid + 1;
	k = start;
	while (i <= mid && j <= end)
	{
		if (num[i] < num[j])
		{
			temp[k] = num[i];
			i++;
		}
		else
		{
			temp[k] = num[j];
			j++;
		}
		k++;
	}
	while (i <= mid)
	{
		temp[k] = num[i];
		k++;
		i++;
	}
	while (j <= end)
	{
		temp[k] = num[j];
		k++;
		j++;
	}
	for (int l = start; l <= end; l++)
		num[l] = temp[l];
}

void	merge_sort(int num[], int start, int end)
{
	int	mid;

	if (start >= end)
		return ;
	mid = (start + end) / 2;
	merge_sort(num, start, mid);
	merge_sort(num, mid + 1, end);
	merge(num, start, mid, end);
}

int	main(void)
{
	int	n;
	int	num[50];
	int	positives;
	int	ones;
	int	zeros;
	int	negatives;
	int	index;
	int	result;

	scanf("%d", &n);
	positives = 0;
	ones = 0;
	zeros = 0;
	negatives = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
		if (num[i] > 1)
			positives++;
		else if (num[i] == 1)
			ones++;
		else if (num[i] == 0)
			zeros++;
		else
			negatives++;
	}
	printf("p: %d o: %d n: %d z: %d\n", positives, ones, negatives, zeros);
	merge_sort(num, 0, n - 1);
	// for (int i = 0; i < n; i++)
	// 	printf("%d ", num[i]);
	index = 0;
	result = 0;
	if (negatives > 0)
	{
		if (negatives % 2 == 0)
		{
			while (index + 1 < n && num[index] < 0)
			{
				result += num[index] * num[index + 1];
				index += 2;
			}
		}
		else
		{
			if (zeros > 0)
			{
				while (index + 2 < n && num[index + 2] < 0)
				{
					result += num[index] * num[index + 1];
					index += 2;
				}
				index += 2; // 음수 하나 0으로 만듦
			}
			else
			{
				while (index + 2 < n && num[index + 2] < 0)
				{
					result += num[index] * num[index + 1];
					index += 2;
				}
				result += num[index];
				index++;
			}
		}
	}
	while (index < n && num[index] == 0)
		index++;
	while (index < n && num[index] == 1)
	{
		result += num[index];
		index++;
	}
	if (positives % 2 == 1)
	{
		result += num[index];
		index++;
	}
	while (index + 1 < n)
	{
		result += num[index] * num[index + 1];
		index += 2;
	}
	printf("%d\n", result);
	return (0);
}
