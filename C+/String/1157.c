#include <stdio.h>

int alpha[27];

int max(int *arr)
{
	int ret;
	
	ret = 1;
	for (int i = 2; i <= 26; i++)
		if (arr[i] > arr[ret])
			ret = i;
	for (int i = 1; i <= 26; i++)
		if (i != ret && arr[i] == arr[ret])
			return ('?');
	return (ret + 'A' - 1);
}

int main(void)
{
	char	word[1000001];
	
	scanf("%s", word);
	for (int i = 0; word[i]; i++)
	{
		if (word[i] < 'a')
			alpha[word[i] - 'A' + 1]++;
		else
			alpha[word[i] - 'a' + 1]++;
	}
	printf("%c\n", max(alpha));
	return (0);
}
