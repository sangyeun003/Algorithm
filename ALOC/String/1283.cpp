#include	<iostream>
#include	<string>

using namespace std;

int	big_alpha[26];
int	small_alpha[26];

void	shortcut(void)
{
	string	s;
	int		i;

	getline(cin, s);
	// 각 단어의 첫 글자 check
	for (i = 0; i < s.length(); i++)
	{
		if (i == 0 || s[i - 1] == ' ')
		{
			if (s[i] >= 'A' && s[i] <= 'Z')
			{
				if (big_alpha[s[i] - 'A'] == 0)
				{
					big_alpha[s[i] - 'A'] = 1;
					small_alpha[s[i] - 'A'] = 1;
					s.insert(i, "[");
					i++;
					s.insert(i + 1, "]");
					i++;
					break;
				}
			}
			else if (s[i] >= 'a' && s[i] <= 'z')
			{
				if (big_alpha[s[i] - 'a'] == 0)
				{
					big_alpha[s[i] - 'a'] = 1;
					small_alpha[s[i] - 'a'] = 1;
					s.insert(i, "[");
					i++;
					s.insert(i + 1, "]");
					i++;
					break;
				}
			}
		}
		while (s[i] != ' ' && i < s.length())
			i++;
	}
	// 각 단어 첫 글자 외의 case
	if (i >= s.length())
	{
		for (i = 0; i < s.length(); i++)
		{
			if (s[i] != ' ')
			{
				if (s[i] >= 'A' && s[i] <= 'Z')
				{
					if (big_alpha[s[i] - 'A'] == 0)
					{
						big_alpha[s[i] - 'A'] = 1;
						small_alpha[s[i] - 'A'] = 1;
						s.insert(i, "[");
						i++;
						s.insert(i + 1, "]");
						i++;
						break;
					}
				}
				else if (s[i] >= 'a' && s[i] <= 'z')
				{
					if (big_alpha[s[i] - 'a'] == 0)
					{
						big_alpha[s[i] - 'a'] = 1;
						small_alpha[s[i] - 'a'] = 1;
						s.insert(i, "[");
						i++;
						s.insert(i + 1, "]");
						i++;
						break;
					}
				}
			}
		}
	}
	cout << s << "\n";
}

int	main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int	n;

	cin >> n;
	cin.ignore(100, '\n');
	for (int i = 0; i < n; i++)
		shortcut();
	return (0);
}
