// 양수는 일단 더함
// - 나오면 - 나올 때까지 따로 더해둠(괄호로 묶기)
#include	<stdio.h>

int	main(void)
{
	char	expression[51];
	int		sum;
	int		negative;
	int		idx;
	int		num;

	scanf("%s", expression);
	idx = 0;
	sum = 0;
	num = 0;
	while (expression[idx])
	{
		if (expression[idx] == '-')
		{
			idx++;
			negative = 0;
			while (expression[idx] != '-' && expression[idx])
			{
				if (expression[idx] == '+')
				{
					negative += num;
					num = 0;
				}
				else
				{
					num = num * 10 + (expression[idx] - '0');
				}
				idx++;
			}
			negative += num;
			sum -= negative;
		}
		else if (expression[idx] == '+')
			idx++;
		else
		{
			while (expression[idx] >= '0' && expression[idx] <= '9')
			{
				num = num * 10 + (expression[idx] - '0');
				idx++;
			}
			sum += num;
		}
		num = 0;
	}
	printf("%d\n", sum);
	return (0);
}
