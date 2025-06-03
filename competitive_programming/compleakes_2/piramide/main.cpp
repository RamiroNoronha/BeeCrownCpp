#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define logs false
using namespace std;

long long int piramideSize(int h)
{
    long long int res = 0;
    res = h * 2;
    for (int i = h - 1; i > 0; i--)
    {
        res += i * 3;
    }

    return res;
}

int main()
{
    int t;
    cin >> t;
    long long int n;
    long long int qtdCartas;
    long long int h = 1;
    long long int total;
    while (t--)
    {
        cin >> n;
        total = 0;
        while (n > 1)
        {
            h = 1;

            while (piramideSize(h) <= n)
            {
                h++;
            }
            h--;
            qtdCartas = piramideSize(h);
            n -= qtdCartas;
            total++;
        }

        cout << total << endl;
    }
}