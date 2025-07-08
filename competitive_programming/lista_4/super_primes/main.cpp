#include <bits/stdc++.h>

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
using namespace std;
using lli = long long;

vector<bool> segmentedSieve(lli L, lli R)
{
    lli lim = sqrt(R);
    vector<bool> mark(lim + 1, false);
    vector<lli> primes;
    for (lli i = 2; i <= lim; ++i)
    {
        if (!mark[i])
        {
            primes.emplace_back(i);
            for (lli j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    vector<bool> isPrime(R - L + 1, true);
    for (lli i : primes)
        for (lli j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}

int main()
{
    _;
    vector<bool> prime = segmentedSieve(1, 1e5 + 1);
    lli n;
    lli pot;
    bool isSuperPrime = true;
    lli index;
    while (cin >> n)
    {
        index = n - 1;
        if (!prime[index])
        {
            cout << "Nada" << endl;
            continue;
        }
        pot = 10;
        isSuperPrime = true;
        while (n)
        {
            index = (n % pot) - 1;
            if (!prime[index])
            {
                isSuperPrime = false;
                break;
            }
            n /= 10;
        }

        if (isSuperPrime)
            cout << "Super" << endl;
        else
            cout << "Primo" << endl;
    }
}