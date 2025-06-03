#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define logs false
using namespace std;

int ficar(int fica, int tira1, int tira2)
{
    int res = 0;
    int diffTira = tira1 > tira2 ? tira1 - tira2 : tira2 - tira1;
    tira1 -= diffTira;
    tira2 -= diffTira;
    int sobrou = tira1 + tira2;

    if (sobrou % 2 == 0)
        return 1;

    return 0;
}

int main()
{
    int t;
    int a, b, c;

    cin >> t;
    while (t--)
    {
        cin >> a >> b >> c;

        int resultA = ficar(a, b, c);
        int resultB = ficar(b, a, c);
        int resultC = ficar(c, a, b);

        cout << resultA << " " << resultB << " " << resultC << endl;
    }
    return 0;
}