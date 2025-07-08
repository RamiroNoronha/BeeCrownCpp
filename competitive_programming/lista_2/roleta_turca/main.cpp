#include <iostream>
#include <vector>
#include <string>
#include <tuple>
using namespace std;
#define INF 0x3f3f3f3f
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define logs true

int S, B;
vector<int> s, b;
vector<vector<int>> memo;

int main()
{
    while (cin >> S >> B && (S && B))
    {
        s = vector<int>(S);
        b = vector<int>(B);
        for (int i = 0; i < S; i++)
            cin >> s[i];
        for (int i = 0; i < B; i++)
        {
            cin >> b[i];
            b[i] *= -1;
        }

        memo = vector<vector<int>>(B + 1, vector<int>(S + 1, -INF));
        int p = 0;
        for (int i = 0; i <= S; i++)
        {
            memo[0][i] = b[0] * (s[i] + s[(i + 1) % S]);
            for (int j = i + 1; j <= S; j++)
            {
                p = j % S;
                memo[0][p] = max(memo[0][(p - 1 + S) % S], b[0] * (s[p] + s[(p + 1) % S]));
                if (logs)
                {
                    cout << "p = " << j << " % " << S << " = " << p << endl;
                    cout << "memo[0][" << p << "] = max(memo[0][" << p - 1 << "] = " << memo[0][p - 1] << ", "
                         << "b[0] * (s[" << p << "] + s[" << (p + 1) % S << "]) = " << b[0] << " * (" << s[p] << " + " << s[(p + 1) % S] << ")) = "
                         << memo[0][p] << endl;
                }
            }
            if (logs)
            {
                cout << "-------------------------" << endl;
            }
            for (int j = 1; j <= B; j++)
            {

                for (int k = j * 2; k <= S; k++)
                {
                    p = (k + i) % S;
                    memo[j][p] = max(memo[j][(p + S - 1) % S], memo[j - 1][(k + S - 2) % S] + b[j] * (s[p] + s[(p + 1) % S]));
                    if (logs)
                    {
                        cout << "p = " << k << " % " << S << " = " << p << endl;
                        cout << "memo[" << j << "][" << p << "] = max("
                             << "memo[" << j << "][" << (p + S - 1) % S << "] = " << memo[j][(p + S - 1) % S] << ", "
                             << "memo[" << j - 1 << "][" << (k + S - 2) % S << "] + b[" << j << "] * (s[" << p << "] + s[" << (p + 1) % S << "]) = "
                             << memo[j - 1][(k + S - 2) % S] << " + " << b[j] << " * (" << s[p] << " + " << s[(p + 1) % S] << ")) = "
                             << memo[j][p] << endl;
                    }
                }
            }

            if (logs)
            {
                cout << "-------------------------" << endl;
                cout << "-------------------------" << endl;
            }
        }

        cout << memo[B][S - 1] << endl;
    }
    return 0;
}