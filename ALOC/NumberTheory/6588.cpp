// endl은 \n보다 느림.
// endl을 \n으로 바꾸니까 정답. testcase가 많아서 그런듯.
#include	<iostream>

using namespace std;

int	main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int	prime[1000001] = {0};	// 0이면 소수, 1이면 소수 아닌 수

	prime[0] = prime[1] = 1;
	for (int i = 2; i * i <= 1000000; i++)
	{
		if (prime[i] == 0)
		{
			for (int j = i; i * j <= 1000000; j++)
				prime[i * j] = 1;
		}
	}
	while (1)
	{
		int	n;
		int	result = 0;

		cin >> n;
		if (n == 0)
			break ;
		for (int i = 3; i <= n / 2; i += 2)		// n >= 6인 짝수. 3 이상의 홀수로만 표현 가능. 2로 표현 가능한 짝수는 only 2+2=4
		{
			if (prime[i] == 0 && prime[n - i] == 0)
			{
				result = i;
				break;
			}
		}
		if (result == 0)
			cout << "Goldbach's conjecture is wrong.\n";
		else
			cout << n << " = " << result << " + " << n - result << "\n";
	}
	return (0);
}
