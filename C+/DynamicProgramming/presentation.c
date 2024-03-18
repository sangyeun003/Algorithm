int	fibo(int n)
{
	if (n < 2)
		return (n);
	return (fibo(n - 1) + fibo(n - 2));
}

int	memo[100] = {0};

int	fibo(int n)
{
	if (n < 2)
		return (memo[n] = n);
	if (memo[n] == 0)
		return (memo[n] = fibo(n - 1) + fibo(n - 2));
	return (memo[n]);
}

int	fibo(int n)
{
	int	f[100];

	f[0] = 0;
	f[1] = 1;
	for (int i = 2; i < n; i++)
		f[i] = f[i - 1] + f[i - 2];
	return (f[n]);
}

