// 3의 배수이면 각 자리 수의 합이 3의 배수
// 3의 배수 & 10의 배수 -> 맨 마지막 자리 0
#include    <stdio.h>
#include    <string.h>

void    bubble_sort(char *str)
{
    int     len;
    char    temp;

    len = strlen(str);
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (str[j] < str[j + 1])
            {
                temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}

void	swap(char *a, char *b)
{
	char	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void    quick_sort(char *str, int start, int end)
{
    int	pivot_idx;
	int	left;
	int	right;
	
	if (start >= end)
		return ;
	pivot_idx = start;
	left = start + 1;
	right = end;
	while (left < right)
	{
		while (str[left] >= str[pivot_idx])
			left++;
		while (str[right] < str[pivot_idx])
			right--;
		if (left < right)
			swap(&str[left], &str[right]);
	}
	if (pivot_idx == right)	// 이미 정렬된 상태
		return ;
	swap(&str[pivot_idx], &str[right]);	// right 위치에 pivot이 옴
	quick_sort(str, start, right - 1);
	quick_sort(str, right + 1, end);
}

int main(void)
{
    char    str[100000];
    int     sum;
	int		len;

    scanf("%s", str);
    if (!strchr(str, (int)'0'))
        printf("-1\n");
    else
    {
        sum = 0;
        for (int i = 0; str[i]; i++)
            sum += str[i] - '0';
        if (sum % 3 != 0)
            printf("-1\n");
        else
        {
            len = strlen(str);
			if (len > 2)
				quick_sort(str, 0, len - 1);
			else
				bubble_sort(str);
            printf("%s\n", str);
        }
    }
    return (0);
}
