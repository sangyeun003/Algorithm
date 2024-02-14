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

void    quick_sort(char *str)
{
    
}

int main(void)
{
    char    str[100000];
    int     sum;

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
            sort(str);
            printf("%s\n", str);
        }
    }
    return (0);
}
