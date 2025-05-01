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

int N, T, K, R, maxValue;
vector<int> X, Y;
vector<vector<int>> dp;

int solve_top_down(int i, int j)
{
    if (i < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    // The item do not fit in the cannon

    if (Y[i] > K)
    {
        // i-1 simbolizes the item not being used, so this solve will get to the case where the item is not used that causes more impact
        return dp[i][j] = solve_top_down(i - 1, j);
    }

    int destruction_not_using_the_ammunition = solve_top_down(i - 1, j);
    int destruction_using_the_ammunition = (j - Y[i] > 0) ? solve_top_down(i - 1, j - Y[i]) + X[i] : 0;

    dp[i][j] = max(destruction_not_using_the_ammunition, destruction_using_the_ammunition);

    maxValue = max(maxValue, dp[i][j]);

    return dp[i][j];
}

void solve_bottom_up()
{
    // The first for runs through the available items
    for (int i = 1; i <= N; i++)
    {
        int poweri = X[i - 1];
        int weigthi = Y[i - 1];

        // The second for runs through the available weights
        for (int k = 0; k <= K; k++)
        {
            // The available weight is less than the weight of the current item, so I will not use that item
            if (k < weigthi)
            {
                dp[i][k] = dp[i - 1][k];
            }
            else
            {
                // If the available weight is greater than or equal to the current item, I can use it
                dp[i][k] = max(dp[i - 1][k], dp[i - 1][k - weigthi] + poweri);
            }

            maxValue = max(maxValue, dp[i][k]);
        }
    }
}

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;
        X = vector<int>(N);
        Y = vector<int>(N);
        for (int i = 0; i < N; i++)
        {
            cin >> X[i] >> Y[i];
        }

        cin >> K;
        cin >> R;

        maxValue = -1;
        // Initialize the dp array with -1 if is top-down or 0 if is bottom-up
        dp = vector<vector<int>>(N + 1, vector<int>(K + 1, 0));
        solve_bottom_up();

        if (maxValue == -1)
            continue;

        if (maxValue >= R)
        {
            cout << "Missao completada com sucesso" << endl;
        }
        else
        {
            cout << "Falha na missao" << endl;
        }
    }

    return 0;
}