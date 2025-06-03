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

vector<vector<int>> dp;
long long int s;
string bin;
int t;
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> bin;
        s = 0;
        for (int i = 0; i < bin.length(); i++)
        {
            if (bin[i] == '1')
            {
                s += 1;
            }
        }

        cout << s << endl;
    }
}