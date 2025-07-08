#include <bits/stdc++.h>

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define MIN 2

using namespace std;
using lli = long long;

#define MAX 2000000
bool prime[MAX];

void crivo()
{
    memset(prime, true, sizeof(prime));
    int div;
    prime[0] = false;
    prime[1] = true;

    for (int i = MIN; i * i < MAX; i++)
    {
        if (!prime[i])
            continue;

        for (int j = i * i; j < MAX; j += i)
        {
            prime[j] = false;
        }
    }
}

int main()
{
    _;
    crivo();
    lli N, T;
    lli number;
    set<lli> primesSet;
    cin >> T;
    while (T--)
    {
        cin >> N;
        primesSet.clear();
        for (lli i = 0; i < N; i++)
        {
            cin >> number;
            if (number < MAX && prime[number])
            {
                primesSet.insert(number);
            }
        }

        if (primesSet.empty() || primesSet.find(1) == primesSet.end())
        {
            cout << "0" << endl;
            continue;
        }

        for (lli i = MIN; i < MAX; i++)
        {
            if (!prime[i])
                continue;
            if (primesSet.find(i) == primesSet.end())
            {
                cout << i - 1 << endl;
                break;
            }
        }
    }
    return 0;
}