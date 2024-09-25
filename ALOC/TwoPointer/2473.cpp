#include	<iostream>
#include	<algorithm>

using namespace std;

int	n;
long long	minimum_sum;
long long	sol[5000];
long long	ans[3];

void	two_pointer(int start, int end, int target)
{
	long long	sum;

	while (start < end)
	{
		sum = target + sol[start] + sol[end];
		if (labs(target + sol[start] + sol[end]) < labs(minimum_sum))
		{
			ans[0] = target;
			ans[1] = sol[start];
			ans[2] = sol[end];
			minimum_sum = target + sol[start] + sol[end];
		}
		if (target + sol[start] + sol[end] < 0)
			start++;
		else if (target + sol[start] + sol[end] > 0)
			end--;
		else
			break ;
	}
}

int	main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> sol[i];
	sort(sol, sol + n);
	ans[0] = sol[0];
	ans[1] = sol[1];
	ans[2] = sol[2];
	minimum_sum = ans[0] + ans[1] + ans[2];
	for (int i = 0; i < n - 2; i++)
		two_pointer(i + 1, n - 1, sol[i]);
	for (int i = 0; i < 3; i++)
		cout << ans[i] << " ";
	return (0);
}
