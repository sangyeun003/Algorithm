#include	<iostream>

using namespace std;

int	main(void)
{
	int	t;

	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		int	a;
		int	b;
		cin >> a >> b;
		cout << "Case #" << i << ": " << a << " + " << b << " = " << a + b << "\n";
	}
	return (0);
}
