#include	<iostream>
#include	<map>
#include	<vector>
#include	<algorithm>

std::map<std::string, int>	num;	// 이름에 대응하는 id 부여
std::vector<int>	relation[100];
int	visited[100];

void	dfs(int start)
{
	visited[start] = 1;
	for (int i = 0; i < relation[start].size(); i++)
	{
		if (visited[relation[start][i]] == 0)
			dfs(relation[start][i]);
	}
}

int	main(void)
{
	int	n;
	int	m;
	int	result;

	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::string	name;

		std::cin >> name;
		num[name] = i;
	}
	std::cin >> m;
	for (int i = 0; i < m; i++)
	{
		std::string	name1, name2;

		std::cin >> name1 >> name2;
		relation[num[name1]].push_back(num[name2]);
		relation[num[name2]].push_back(num[name1]);
	}
	result = 0;
	for (int i = 0; i < n; i++)
	{
		if (visited[i] == 0)
		{
			dfs(i);
			result++;
		}
	}
	std::cout << result << std::endl;
	return (0);
}
