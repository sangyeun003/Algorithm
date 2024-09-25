// 0. musicinfos를 parsing하는 함수
// 1. 시간을 분단위로 바꾸는 함수
// 2. 시간에 따라 문자열 확장하는 함수
// 	- #이 포함된 음에 대해서 총 길이를 구하는 함수
// 3. 확장된 문자열과 내가 들은 음악을 비교하는 함수
#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>

// char	result[5][100];

char	**parse(char *s)
{
	int		i;
	int		j;
	char	**result;


	result = (char **)malloc(5 * sizeof(char*));
	for (i = 0; i < 4; i++)
		result[i] = (char *)malloc(100 * sizeof(char));
	// result[4] = '\0';
	j = 0;

	// 시작 시간
	for (i = 0; i < 5; i++, j++)
		result[0][i] = s[j];
	result[0][i] = '\0';
	j++;	// 콤마

	// 종료 시간
	for (i = 0; i < 5; i++, j++)
		result[1][i] = s[j];
	result[1][i] = '\0';
	j++;	// 콤마

	// 노래 제목
	for (i = 0; s[j] != ','; i++, j++)
		result[2][i] = s[j];
	result[2][i] = '\0';
	j++;	// 콤마

	// 멜로디
	for (i = 0; s[j] != '\0'; i++, j++)
		result[3][i] = s[j];
	result[3][i] = '\0';

	return result;
}

int	main(void)
{
	char	**result = parse("12:00,12:14,HELLO,CDEFGAB");
	for (int i = 0; i < 4; i++)
		printf("%s\n", result[i]);
	return (0);
}