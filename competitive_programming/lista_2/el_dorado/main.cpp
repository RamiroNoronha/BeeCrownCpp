#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;
#define INF 0x3f3f3f3f
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define logs true

vector<int> A;
vector<vector<long long int>> dp;
int n, k;

void ssdcMaxProgDin()
{
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        dp[i][1] = 1;
    }

    // go into every state
    for (int i = 2; i <= k; i++)
    {

        for (int j = i - 1; j < n; j++)
        {
            dp[j][i] = 0;
            for (int l = 0; l < j; l++)
            {
                if (A[j] >= A[l])
                {

                    dp[j][i] += (dp[l][i - 1]);
                }
            }
        }
    }
}

int main()
{
    while (cin >> n >> k)
    {
        if (n == 0 && k == 0)
            break;
        A = vector<int>(n);
        dp = vector<vector<long long>>(n, vector<long long>(k + 1, 0));

        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        ssdcMaxProgDin();
        long long result = 0;
        for (int i = 0; i < n; i++)
        {

            result += dp[i][k];
        }

        cout << result << endl;
    }

    return 0;
}
