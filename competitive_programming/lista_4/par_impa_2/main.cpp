#include <bits/stdc++.h>
#define MIN 2
#define MAX 100000001
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

#define lli long long int

using namespace std;

vector<bool> prime;
vector<long long> factor;
vector<long long> expo;
vector<long long> variable;

void crivo()
{
    prime = vector<bool>(MAX, true);
    int div;
    prime[0] = false;
    prime[1] = false;

    for (int i = MIN; i * i <= MAX; i++)
    {
        if (!prime[i])
            continue;

        for (int j = i * i; j <= MAX; j += i)
        {
            prime[j] = false;
        }
    }
}

lli qtdPrimes(lli left, lli right)
{
    lli totalPrimes = 0;
    for (lli i = left; i <= right; i++)
    {
        if (prime[i])
            totalPrimes++;
    }
    return totalPrimes;
}

// https://www.ime.usp.br/~yw/lic-mat-not-2005/mac110/eps/ep1.pdf
bool isCombinationOdd(lli n, lli k)
{
    for (int i = 0; i < 32; i++)
    {
        if ((k & (1 << i)) > (n & (1 << i)))
            return false;
    }
    return true;
}

int main()
{
    _;
    lli A, B;

    cin >> A >> B;
    if (A == B)
    {
        cout << '?' << endl;
        return 0;
    }
    crivo();

    lli left = min(A, B);
    lli right = max(A, B);

    lli totalPrimes = qtdPrimes(left, right);

    if (totalPrimes == 0)
    {
        cout << "Bob" << endl;
        return 0;
    }

    lli k_comb = right - left;
    lli n_comb = totalPrimes + k_comb - 1;

    if (isCombinationOdd(n_comb, k_comb))
        cout << "Alice" << endl;
    else
        cout << "Bob" << endl;

    return 0;
}