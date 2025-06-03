#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define logs false

using namespace std;

int main()
{
    long long int CA, CB;

    std::cin >> CA >> CB;

    long long int ba, bv, bc;

    std::cin >> ba >> bv >> bc;

    long long int qtdCA, qtdCB;

    qtdCA = 2 * ba + bv;
    qtdCB = 3 * bc + bv;

    long long int diff = 0;

    if (qtdCA > CA)
    {
        diff += qtdCA - CA;
    }

    if (qtdCB > CB)
    {
        diff += qtdCB - CB;
    }

    cout << diff << "\n";

    return 0;
}