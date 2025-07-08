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

string s, r;
vector<vector<int>> memo;
int topDown(int i, int j)
{
    if (i < 0 || j < 0)
        return 0;

    if (memo[i][j] != -1)
        return memo[i][j];

    if (s[i] == r[j])
    {
        return memo[i][j] = 1 + topDown(i - 1, j - 1);
    }

    return memo[i][j] = max(topDown(i - 1, j), topDown(i, j - 1));
}

int main()
{
    cin >> s;
    cin >> r;

    memo = vector<vector<int>>(s.size(), vector<int>(r.size(), -1));
    int result = topDown(s.size() - 1, r.size() - 1);
    cout << result << endl;
    return 0;
}