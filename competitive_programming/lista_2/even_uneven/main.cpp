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

vector<int> v;
int n;
vector<vector<int>> dp;

int topDown(int i, int j)
{

    if (i >= j)
        return 0;

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int leftResult = i < j ? min(v[i + 1] + i + 1 < j ? topDown(i + 2, j) : 0, v[j] + i + 1 < j ? topDown(i + 1, j - 1) : 0) : 0;
    int leftLocal = v[i] + leftResult;
    int rightResult = i < j ? min(v[i] + i + 1 < j ? topDown(i + 1, j - 1) : 0, v[j - 1] + i + 1 < j ? topDown(i, j - 2) : 0) : 0;
    int rightLocal = v[j] + rightResult;

    return dp[i][j] = max(leftLocal, rightLocal);
}

// void compute_dp()
// {

//     int i = 0;
//     int j = 2 * n - 1;
//     int sum = 0;

//     if (v[i] > v[j])
//     {
//         dp[i][j] = v[i];
//         i++;
//     }
//     else
//     {
//         dp[i][j] = v[j];
//         j--;
//     }
//     cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
//     int leftResult = 0;
//     int rightResult = 0;
//     while (i > 0 && j < 2 * n)
//     {
//         dp[i][j] = max(v[i] + min(v[i + 1] + dp[i + 2][j], v[j] + dp[i + 1][j - 1]), v[j] + min(v[i] + dp[i + 1][j - 1], v[j - 1] + dp[i][j - 2]));
//     }
// }

// void compute_dp()
// {

//     int i = n - 1;
//     int j = n;

//     if (v[i] > v[j])
//     {
//         dp[i][j] = v[i];
//     }
//     else
//     {
//         dp[i][j] = v[j];
//     }
//     if (logs)
//     {
//         cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
//     }
//     i--;
//     j++;
//     while (i >= 0 && j <= 2 * n)
//     {
//         dp[i + 1][j] = max(v[i + 1] + dp[i + 2][j], v[j] + dp[i + 1][j - 1]);
//         dp[i][j - 1] = max(v[i] + dp[i + 1][j - 1], v[j - 1] + dp[i][j - 2]);
//         dp[i][j] = max(v[i] + min(v[i + 1] + dp[i + 2][j], v[j] + dp[i + 1][j - 1]), v[j] + min(v[i] + dp[i + 1][j - 1], v[j - 1] + dp[i][j - 2]));
//         if (logs)
//         {
//             cout << "dp[" << i << "][" << j << "] = max("
//                  << "v[" << i << "] + min(v[" << i + 1 << "] + dp[" << i + 2 << "][" << j << "] (" << v[i + 1] << " + " << dp[i + 2][j] << "), "
//                  << "v[" << j << "] + dp[" << i + 1 << "][" << j - 1 << "] (" << v[j] << " + " << dp[i + 1][j - 1] << ")), "
//                  << "v[" << j << "] + min(v[" << i << "] + dp[" << i + 1 << "][" << j - 1 << "] (" << v[i] << " + " << dp[i + 1][j - 1] << "), "
//                  << "v[" << j - 1 << "] + dp[" << i << "][" << j - 2 << "] (" << v[j - 1] << " + " << dp[i][j - 2] << ")))" << endl;

//             cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
//         }
//         i--;
//         j++;
//     }
// }

int bottomUp(int n, vector<int> &v)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i)
        dp[i][i] = v[i];

    for (int len = 2; len <= n; ++len)
    {
        for (int i = 0; i <= n - len; ++i)
        {
            int j = i + len - 1;

            int pickLeft = v[i] + min(
                                      (i + 2 <= j ? dp[i + 2][j] : 0),
                                      (i + 1 <= j - 1 ? dp[i + 1][j - 1] : 0));

            int pickRight = v[j] + min(
                                       (i <= j - 2 ? dp[i][j - 2] : 0),
                                       (i + 1 <= j - 1 ? dp[i + 1][j - 1] : 0));

            dp[i][j] = max(pickLeft, pickRight);
        }
    }

    return dp[0][n - 1]; // resposta para o jogo completo
}

int main()
{
    while (cin >> n)
    {
        if (n == 0)
            break;
        int N = 2 * n;
        v = vector<int>(N);
        for (int i = 0; i < N; i++)
        {
            cin >> v[i];
            v[i] = (v[i] % 2 == 0) ? 1 : 0;
        }
        if (logs)
        {
            for (int i = 0; i < N; i++)
            {
                cout << v[i] << " ";
            }
            cout << endl;
        }

        int asn = bottomUp(N, v);
        cout << asn << endl;
    }
    return 0;
}