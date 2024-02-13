#include	<stdio.h>
#include	<stdlib.h>
#include	<math.h>
#include	<string.h>

char	result[10];
int		smallest = 1000000000;

int	d_to_ten(char *result, int d)
{
	int	ten;
	int	arr[9] = {0};

	for (int i = 0; i < d; i++)
		arr[i] = (int)pow(d, i);
	ten = 0;
	for (int i = 0; i < d; i++)
		ten += (result[d - i - 1] - '0') * arr[i];
	return (ten);
}

// int	permutation(int n, int r, int depth)
// {
// 	int	smallest;

// 	if ()
// }
void swap(char *a, char *b) 
{
    char	temp;
	
	temp = *a;
    *a = *b;
    *b = temp;
}

void	generatePermutations(char *str, int start, int end, int d) 
{
    if (start == end) 
	{
		if (d_to_ten(str, d) < smallest)
			smallest = d_to_ten(str, d);
    } 
	else 
	{
        for (int i = start; i <= end; i++) 
		{
            // 현재 위치의 문자와 다음 위치의 문자를 교환
            swap(&str[start], &str[i]);
            
            // 다음 위치의 순열을 생성하기 위해 재귀 호출
            generatePermutations(str, start + 1, end, d);

            // 다시 원래대로 복원
            swap(&str[start], &str[i]);
        }
    }
}

int	main(void)
{
	int	n;
	int	d;

	scanf("%d %d", &n, &d);
	printf("0");
	// result = malloc(sizeof(9));
	// if (!result)
	// 	exit(1);
	// result = "000000000";
	result[0] = '1';
	result[1] = '0';
	for (int i = 2; i < d; i++)
		result[i] = i + '0';
	result[d] = NULL;
	printf("0");
	generatePermutations(result, 0, n - 1, d);
	if (smallest == 100000000)
		printf("-1\n");
	else
		printf("%d\n", smallest);
	return (0);
}
