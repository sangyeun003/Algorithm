// 슬라이딩 윈도우
#include	<stdio.h>

int	dna(char *s, int *acgt, int p_len)
{
	int	start;
	int	end;
	int	now_acgt[4] = {0};
	int	result;

	result = 0;
	for (end = 0; end < p_len; end++)
	{
		if (s[end] == 'A')
			now_acgt[0]++;
		else if (s[end] == 'C')
			now_acgt[1]++;
		else if (s[end] == 'G')
			now_acgt[2]++;
		else if (s[end] == 'T')
			now_acgt[3]++;
	}
	if (now_acgt[0] >= acgt[0] && now_acgt[1] >= acgt[1] && now_acgt[2] >= acgt[2] && now_acgt[3] >= acgt[3])
		result++;
	start = 0;
	while (s[end])
	{
		// 맨 뒤 포인터 하나 미뤘을 때 총 count 갱신
		if (s[end] == 'A')
			now_acgt[0]++;
		else if (s[end] == 'C')
			now_acgt[1]++;
		else if (s[end] == 'G')
			now_acgt[2]++;
		else if (s[end] == 'T')
			now_acgt[3]++;

		// 맨 앞 포인터 하나 미뤘을 때 총 count 갱신
		if (s[start] == 'A')
			now_acgt[0]--;
		else if (s[start] == 'C')
			now_acgt[1]--;
		else if (s[start] == 'G')
			now_acgt[2]--;
		else if (s[start] == 'T')
			now_acgt[3]--;
		start++;
		// for (int i = start; i <= end; i++)
		// 	printf("%c", s[i]);
		// printf(("\n"));
		if (now_acgt[0] >= acgt[0] && now_acgt[1] >= acgt[1] && now_acgt[2] >= acgt[2] && now_acgt[3] >= acgt[3])
			result++;

		end++;
	}
	return (result);
}

int	main(void)
{
	int		s_len;
	int		p_len;
	char	s[1000001];
	char	p[1000001];
	int		acgt[4];

	scanf("%d %d", &s_len, &p_len);
	scanf("%s", s);
	scanf("%d %d %d %d", &acgt[0], &acgt[1], &acgt[2], &acgt[3]);
	printf("%d\n", dna(s, acgt, p_len));
	return (0);
}
