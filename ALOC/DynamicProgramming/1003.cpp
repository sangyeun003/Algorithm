// t[i][0]: i일 때 호출되는 0의 횟수
// t[i][1]: i일 때 호출되는 1의 횟수
#include    <iostream>

int main(void)
{
    int dp[41][2];
    int t;
    int n;

    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[1][0] = 0;
    dp[1][1] = 1;
    for (int i = 2; i <= 40; i++)
    {
        dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
        dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
    }
    std::cin >> t;
    for (int i = 0; i < t; i++)
    {
        std::cin >> n;
        std::cout << dp[n][0] << ' ' << dp[n][1] << std::endl;
    }
    return (0);
}
