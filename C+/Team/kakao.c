#include	<stdio.h>
#include	<stdlib.h>

int	solution(long long number[], size_t numbers_len)
{
	int	*ans = (int *)malloc(sizeof(int) * numbers_len);

	for (size_t i = 0; i < numbers_len; i++)
	{
		long long	temp = number[i] / 2;
	
		while (temp > 0)
		{
			if (temp % 2 == 0)
				break ;
			temp /= 4;
		}
		if (temp == 0)
			ans[i] = 1;
		else
			ans[i] = 0;
	}
	return (ans);
}