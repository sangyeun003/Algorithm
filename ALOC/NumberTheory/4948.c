#include <stdio.h>

#define N	246913

int prime[N + 1];

void make_prime(void)
{
	prime[0] = -1;
	prime[1] = -1;
	for (int i = 2; i * i <= N; i++)
	{
		if (prime[i] != -1)
			for (int j = 2; i * j <= N; j++)
				prime[i * j] = -1;
	}
}

void	print_prime(int n)
{
	int num;
	
	num = 0;
	for (int i = n + 1; i <= 2 * n; i++)
		if (prime[i] == 0)
			num++;
	printf("%d\n", num);
	return ;
}

int main(void)
{
	int n;
	
	make_prime();
	while (1)
	{
		scanf("%d", &n);
		if (n == 0)
			return (0);
		print_prime(n);
	}
	return (0);
}
