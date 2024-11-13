// 컴파일: g++ 1339.cpp -o 1339 -std=c++11
#include	<iostream>
#include	<map>
#include	<cmath>
#include	<algorithm>

using namespace	std;

bool	compare(pair<char, int>& a, pair<char, int>& b)
{
	return a.second > b.second;
}

int	main(void)
{
	string	words[10];
	map<char, int>	weight = {{'A', 0}, {'B', 0}, {'C', 0}, {'D', 0}, {'E', 0}, {'F', 0}, {'G', 0}, {'H', 0}, {'I', 0}, {'J', 0}};
	int		n;
	int		result;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> words[i];
		for (int j = 0; j < words[i].length(); j++)
			weight[words[i][j]] += pow(10, words[i].length() - j - 1);
	}
	// 정렬을 하기 위해 map을 vector로 복사
	vector<pair<char, int> >	sorted_weight(weight.begin(), weight.end());

	// second 기준으로 정렬
	sort(sorted_weight.begin(), sorted_weight.end(), compare);

	// for (int i = 0; i < 10; i++)
	// 	cout << sorted_weight[i].second << "\n";
	result = 0;
	for (int i = 0; i < 10; i++)
		result += sorted_weight[i].second * (9 - i);
	cout << result << "\n";
	return (0);
}
