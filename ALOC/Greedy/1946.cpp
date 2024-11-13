#include	<iostream>
#include	<algorithm>
#include	<vector>

using namespace	std;

bool	compare(pair<int, int>& a, pair<int, int>& b)
{
	return a.first < b.first;
}

int	main(void)
{
	int						t;
	int						n;
	vector<pair<int, int> >	scores;

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		scores.clear();
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			int	first, second;
			cin >> first >> second;
			scores.push_back(make_pair(first, second));
		}
		sort(scores.begin(), scores.end(), compare);

		int	result = 1;
		int	second_min = scores[0].second;
		for (int j = 1; j < n; j++)
		{
			if (scores[j].second < second_min)
			{
				result++;
				second_min = scores[j].second;
			}
		}
		cout << result << "\n";
	}
	return (0);
}
