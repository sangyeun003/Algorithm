#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int	cal_should_deliver(int n, int deliveries[])
{
	int	result = 0;

	for (int i = 0; i < n; i++)
		result += deliveries[i];
	return result;
}


// deliveries_len은 배열 deliveries의 길이입니다.
// pickups_len은 배열 pickups의 길이입니다.
long long solution(int cap, int n, int deliveries[], size_t deliveries_len, int pickups[], size_t pickups_len) 
{
    long long	answer = 0;
	long long	should_deliver;
	long long	current = 0;			// 현재 트럭에 있는 상자의 수
	long long	current_deliver = 0;	// 현재 트럭에 남은 배달해야 되는 상자 수
	long long	current_pickup = 0;		// 현재 트럭에 있는 빈 상자 개수

	while (1)
	{
		int	start = 0;

		should_deliver = cal_should_deliver(n, deliveries);
		if (should_deliver == 0)
			break ;

		current_deliver = should_deliver;
		for (int i = n - 1; i >= 0; i--)	// 맨 뒤에서부터 순회하면서 배달할거 count
		{
			if (current_deliver > 0 && deliveries[i] > 0)	// 버리기
			{
				if (deliveries[i] > current_deliver)
				{
					deliveries[i] -= current_deliver;
					current_deliver = 0;
				}
				else
				{
					current_deliver -= deliveries[i];
					deliveries[i] = 0;
				}
				if (i + 1 > start)
					start = i + 1;
			}
			if (pickups[i] > 0 && current_pickup < cap)
			{
				int	max_can_current_pickup = cap - current_pickup;	// 현재 추가로 실을 수 있는 최대 상자 개수
				if (pickups[i] < max_can_current_pickup)
				{
					current_pickup += pickups[i];
					pickups[i] = 0;
				}
				else
				{
					current_pickup = cap;
					pickups[i] -= max_can_current_pickup;
				}
				if (i + 1 > start)
					start = i + 1;
			}
		}
		answer += start;
	}
    return 2 * answer;
}

// 현재 배달이 남은 상자의 개수를 세는 함수
// 현재 픽업해야되는 상자의 개수를 세는 함수