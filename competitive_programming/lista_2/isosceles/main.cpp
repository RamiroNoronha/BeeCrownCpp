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
int n, maxValue = 0;
vector<int> v, dp;

// top-down approach generate stack over flow
int compute_dp(int i)
{
    if (i < 0 || i >= n)
        return 0;

    if (i == 0 || i == n - 1)
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
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || i == n - 1)
        {
            dp[i] = 1;
            continue;
        }

        dp[i] = min(dp[i - 1] + 1, v[i]);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (i == 0 || i == n - 1)
            continue;

        dp[i] = min(dp[i + 1] + 1, dp[i]);

        maxValue = max(maxValue, dp[i]);
    }
}

int main()
{

    cin >> n;

    v = vector<int>(n);
    dp = vector<int>(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    compute_dp_bottom_up();

    cout << maxValue << endl;
}