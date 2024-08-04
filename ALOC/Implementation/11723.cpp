#include	<iostream>
#include	<string>

using namespace std;

int	set[21];

void	add(int x)
{
	set[x] = 1;
}

void	remove(int x)
{
	set[x] = 0;
}

void	check(int x)
{
	cout << set[x] << "\n";
}

void	toggle(int x)
{
	set[x] == 1 ? set[x] = 0 : set[x] = 1;
}

void	all(void)
{
	for (int i = 1; i <= 20; i++)
		set[i] = 1;
}

void	empty(void)
{
	for (int i = 1; i <= 20; i++)
		set[i] = 0;
}

int	main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int		m;
	string	operation;
	int		x;

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> operation;
		if (operation.compare("add") == 0)
		{
			cin >> x;
			add(x);
		}
		else if (operation.compare("remove") == 0)
		{
			cin >> x;
			remove(x);
		}
		else if (operation.compare("check") == 0)
		{
			cin >> x;
			check(x);
		}
		else if (operation.compare("toggle") == 0)
		{
			cin >> x;
			toggle(x);
		}
		else if (operation.compare("all") == 0)
			all();
		else if (operation.compare("empty") == 0)
			empty();
	}
	return (0);
}
