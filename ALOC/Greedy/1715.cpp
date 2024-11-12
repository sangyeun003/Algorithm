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

		// 내가 시도했던 방법 -> 시간 초과
		// for (int i = 0; i < nums.size(); i++)
		// {
		// 	if (nums[i] > temp)
		// 	{
		// 		nums.insert(nums.begin() + i, temp);
		// 		break ;
		// 	}
		// }
		// if (old_size == nums.size())
		// 	nums.push_back(temp);

		// lower_bound(): 특정 수보다 >=인 위치를 찾아서 return
		// log n
		auto	position = lower_bound(nums.begin(), nums.end(), temp);
		nums.insert(position, temp);
		// cout << "\n";
		// for (int num : nums)
		// 	cout << num << " ";
		// cout << "\n";
		// cout << "size: " << nums.size() << "\n\n";
	}
	cout << result << "\n";
	return (0);
}
