#include	<iostream>
#include	<vector>
#include	<string>
#include	<algorithm>

using namespace std;

int				list_length;
vector<string>	list[50];

void	print_list(void)
{
	for (int i = 0; i < list_length; i++)
	{
		cout << "[ ";
		for (int j = 0; j < list[i].size(); j++)
			cout << list[i][j] << " ";
		cout << "]\n";
	}
}

void	check(void)
{
	string	s;

	cin >> s;
	if (list_length == 0)
	{
		list[0].push_back(s);
		list_length++;
	}
	else
	{
		sort(list, list + list_length);
		int	left;
		int	mid;
		int	right;

		left = 0;
		right = list_length - 1;
		while (left <= right)
		{
			mid = (left + right) / 2;
			if (list[mid][0][0] == s[0])
			{
				// 비교
				if (list[mid][0].length() < s.length())
				{
					int	i;
					for (i = 0; i < list[mid][0].length(); i++)
					{
						if (list[mid][0][i] != s[i])
						{
							if (list[mid][0][i] < s[i])
								left = mid + 1;
							else
								right = mid - 1;
							break;
						}
					}
					if (i == list[mid][0].length())
					{
						list[mid].push_back(s);
						sort(list[mid].rbegin(), list[mid].rend());
						break;
					}
				}
				else
				{
					int	i;
					for (i = 0; i < s.length(); i++)
					{
						if (list[mid][0][i] != s[i])
						{
							if (list[mid][0][i] < s[i])
								left = mid + 1;
							else
								right = mid - 1;
							break;
						}
					}
					if (i == s.length())
					{
						list[mid].push_back(s);
						sort(list[mid].rbegin(), list[mid].rend());
						break;
					}
				}
			}
			else if (list[mid][0][0] < s[0])
				left = mid + 1;
			else
				right = mid - 1;
		}
		if (left > right)
		{
			list[list_length].push_back(s);
			list_length++;
		}
	}
}

int	main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int	n;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		check();
		// print_list();
	}
	cout << list_length;
	return (0);
}
