// max(left, right) + 1
#include <iostream>
#include <vector>
#include <string>
#include <tuple>
using namespace std;
#define INF 0x3f3f3f3f
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define logs false
int N, maxValue = 0;
vector<int> v, dp;

// top-down approach generate stack over flow
int compute_dp(int i)
{
    if (i < 0 || i >= N)
        return 0;

    if (i == 0 || i == N - 1)
        return dp[i] = 1;

    if (dp[i] != 0)
        return dp[i];

    int height = v[i];
    int left = compute_dp(i - 1);
    int right = compute_dp(i + 1);

    int minHeight = min(left, right);
    dp[i] = min(minHeight + 1, height);

    maxValue = max(maxValue, dp[i]);

    return dp[i];
}

void compute_dp_bottom_up()
{
    for (int i = 0; i < N; i++)
    {
        if (i == 0 || i == N - 1)
        {
            dp[i] = 1;
            continue;
        }

        dp[i] = min(dp[i - 1] + 1, v[i]);
    }

    for (int i = N - 1; i >= 0; i--)
    {
        if (i == 0 || i == N - 1)
            continue;

        dp[i] = min(dp[i + 1] + 1, dp[i]);

        maxValue = max(maxValue, dp[i]);
    }
}

int main()
{

    cin >> N;

    v = vector<int>(N);
    dp = vector<int>(N, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    compute_dp_bottom_up();

    cout << maxValue << endl;
}