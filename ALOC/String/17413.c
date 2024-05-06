#include	<stdio.h>

int	main(void)
{
	char	str[100001];
	int		temp;
	int		i;

	scanf("%[^\n]s", str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '<')
		{
			while (str[i] != '>')
			{
				printf("%c", str[i]);
				i++;
			}
			printf("%c", str[i]);
		}
		else if (str[i] == ' ')
			printf("%c", str[i]);
		else
		{
			temp = i;
			while ((str[i + 1] >= '0' && str[i + 1] <= '9') || (str[i + 1] >= 'a' && str[i + 1] <= 'z'))
				i++;
			for (int j = i; j >= temp; j--)
				printf("%c", str[j]);
		}
		i++;
	}
	return (0);
}
