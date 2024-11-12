#include	<iostream>
#include	<algorithm>
#include	<vector>

using namespace std;

int	main(void)
{
	int			n;
	vector<int>	nums;
	int			result;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int	num;

		cin >> num;
		nums.push_back(num);
	}
	sort(nums.begin(), nums.end());

	result = 0;
	while (nums.size() > 1)
	{
		int	temp;
		int	old_size;

		temp = nums[0] + nums[1];
		result += temp;

		nums.erase(nums.begin());
		nums.erase(nums.begin());

		old_size = nums.size();
		auto	position = lower_bound(nums.begin(), nums.end(), temp);
		nums.insert(position, temp);
	}
	cout << result << "\n";
	return (0);
}