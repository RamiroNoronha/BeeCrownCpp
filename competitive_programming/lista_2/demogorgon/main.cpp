#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <set>
using namespace std;
#define INF 0x3f3f3f3f
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define logs false
int n, P, maxDamage = 0, local = 0;
vector<int> D, M;
vector<vector<int>> dp;
void demogorgon()
{
    int indice = 0;
    int maxValue = 0;
    dp[0][0] = 0;
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        local += D[i - 1];
        maxValue = min(local, P);
        for (int d = 1; d <= maxValue; d++)
        {
            indice = D[i - 1] <= d ? d - D[i - 1] : 0;

            dp[i][d] = min(dp[i - 1][d], dp[i - 1][indice] + M[i - 1]);
        }
    }
}

int main()
{
    while (cin >> n >> P)
    {
        D = vector<int>(n);
        M = vector<int>(n);
        maxDamage = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> D[i] >> M[i];
            maxDamage += D[i];
        }

        if (maxDamage < P)
        {
            cout << -1 << endl;
            continue;
        }

        dp = vector<vector<int>>(n + 1, vector<int>(P + 1, INF));
        demogorgon();

        if (logs)
        {
            for (int i = 0; i <= n; i++)
            {
                for (int j = 0; j <= P; j++)
                {
                    int value = dp[i][j] == INF ? -1 : dp[i][j];
                    cout << value << " ";
                }
                cout << endl;
            }
        }
        int ans = dp[n][P] != INF ? dp[n][P] : -1;
        cout << ans << endl;
    }
}