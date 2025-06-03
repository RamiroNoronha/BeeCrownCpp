#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <string>
using namespace std;
#define INF 0x3f3f3f3f
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define logs false

int main()
{

    int a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, 0));

    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            if (i == j)
            {
                dp[i][j] == 0;
                continue;
            }

            int min_e = INF;
            for (int k = 1; k < i; k++)
                min_e = min(dp[i - k][j] + dp[k][j], min_e);
            for (int k = 1; k < j; k++)
                min_e = min(dp[i][j - k] + dp[i][k], min_e);

            dp[i][j] = 1 + min_e;
        }
    }

    cout << dp[a][b] << endl;
}
