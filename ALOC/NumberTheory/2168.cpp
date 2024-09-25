#include	<iostream>

using namespace std;

int	gcd(int x, int y)
{
	if (y == 0)
		return (x);
	return (gcd(y, x % y));
}

int	main(void)
{
	int	x;
	int	y;

	cin >> x >> y;
	cout << x + y - gcd(x, y);
	return (0);
}
