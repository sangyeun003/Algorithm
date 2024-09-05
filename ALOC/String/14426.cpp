// 이분 탐색 + 문자열 비교
#include	<iostream>
#include	<algorithm>
#include	<string>

using namespace std;

string	s[10000];
int		n;
int		m;
int		result;

void	prefix(void)
{
	int		left;
	int		mid;
	int		right;
	string	str;

	cin >> str;
	left = 0;
	right = n - 1;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (s[mid][0] == str[0])
		{
			int	idx;
			for (idx = 0; idx < str.length(); idx++)
				if (s[mid][idx] != str[idx])
				{
					if (s[mid][idx] < str[idx])
						left = mid + 1;
					else
						right = mid - 1;
					break;
				}
			if (idx == str.length())
			{
				result++;
				break;
			}
		}
		else if (s[mid][0] < str[0])
			left = mid + 1;
		else
			right = mid - 1;
	}
}

int	main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	sort(s, s + n);
	for (int i = 0; i < m; i++)
		prefix();
	cout << result << "\n";
	return (0);
}
