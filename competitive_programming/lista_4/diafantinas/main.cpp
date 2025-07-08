#include <bits/stdc++.h>

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

#define MOD 1300031
const int MAXN = 2000001;
using namespace std;
using lli = long long;

lli fat[MAXN];

void precomputeFactorials()
{
    fat[0] = 1;
    for (int i = 1; i < MAXN; i++)
    {
        fat[i] = (fat[i - 1] * i) % MOD;
    }
}

lli power(lli base, lli exp)
{
    lli res = 1;
    base %= MOD;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

lli modInverse(lli n)
{
    return power(n, MOD - 2);
}

lli solve(lli n, lli c)
{
    return (fat[n] * modInverse((fat[c] * fat[n - c]) % MOD)) % MOD;
}

int main()
{
    _;
    precomputeFactorials();
    lli T, N, C;
    cin >> T;
    while (T--)
    {
        cin >> N >> C;

        std::cout << solve(N + C - 1, C) << "\n";
    }
}