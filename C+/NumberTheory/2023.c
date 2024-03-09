// #include	<stdio.h>

// int	is_interest(int	n, char prime[])
// {
// 	if (prime[n] == 1)
// 		return (0);
// 	else
// 	{
// 		if (n < 10)
// 			return (1);
// 		else
// 			return (is_interest(n / 10, prime));
// 	}
// }

// int	main(void)
// {
// 	int	n;
// 	// 0이면 소수, 1이면 not 소수
// 	char	prime[1000000] = {0};	

// 	scanf("%d", &n);
// 	prime[0] = 1;
// 	prime[1] = 1;
// 	for (int i = 2; i <= 1000; i++)
// 	{
// 		if (prime[i] == 0)
// 		{
// 			for (int j = 2; i * j < 1000000; j++)
// 				prime[i * j] = 1;
// 		}
// 	}
// 	switch (n)
// 	{
// 	case 1:
// 		for (int i = 2; i < 7; i++)
// 		{
// 			if (prime[i] == 0)
// 				printf("%d\n", i);
// 		}
// 		break;
// 	case 2:
// 		for (int i = 11; i <= 97; i++)
// 		{
// 			if (prime[i] == 0 && is_interest(i, prime) == 1)
// 				printf("%d\n", i);
// 		}
// 		break;
// 	case 3:
// 		for (int i = 101; i <= 997; i++)
// 		{
// 			if (prime[i] == 0 && is_interest(i, prime) == 1)
// 				printf("%d\n", i);
// 		}
// 		break;
// 	case 4:
// 		for (int i = 1001; i <= 9997; i++)
// 		{
// 			if (prime[i] == 0 && is_interest(i, prime) == 1)
// 				printf("%d\n", i);
// 		}
// 		break;
// 	case 5:
// 		for (int i = 10001; i <= 99997; i++)
// 		{
// 			if (prime[i] == 0 && is_interest(i, prime) == 1)
// 				printf("%d\n", i);
// 		}
// 		break;
// 	case 6:
// 		for (int i = 100001; i <= 999997; i++)
// 		{
// 			if (prime[i] == 0 && is_interest(i, prime) == 1)
// 				printf("%d\n", i);
// 		}
// 		break;
// 	case 7:
// 		for (int i = 1000001; i <= 9999997; i++)
// 		{
// 			if (prime[i] == 0 && is_interest(i, prime) == 1)
// 				printf("%d\n", i);
// 		}
// 		break;
// 	case 8:
// 		for (int i = 10000001; i <= 99999997; i++)
// 		{
// 			if (prime[i] == 0 && is_interest(i, prime) == 1)
// 				printf("%d\n", i);
// 		}
// 		break;
// 	}
// 	return (0);
// }
#include	<stdio.h>

int	is_prime(int n)
{
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			return (0);
	}
	return (1);
}

void	print_interest_prime(int prime, int n)
{
	if (n == 0)
	{
		printf("%d\n", prime);
		return ;
	}
	for (int i = 1; i < 10; i += 2)
	{
		if (is_prime(10 * prime + i) == 1)
			print_interest_prime(10 * prime + i, n - 1);
	}
}

int	main(void)
{
	int	n;

	scanf("%d", &n);
	print_interest_prime(2, n - 1);
	print_interest_prime(3, n - 1);
	print_interest_prime(5, n - 1);
	print_interest_prime(7, n - 1);
	return (0);
}
