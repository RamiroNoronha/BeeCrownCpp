#include <bits/stdc++.h>

#define MAX 2000001
#define MIN 2

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

using namespace std;

vector<bool> prime;
vector<long long> factor;
vector<long long> expo;
vector<long long> variable;

void crivo()
{
    prime = vector<bool>(MAX, true);
    factor = vector<long long>(MAX);
    expo = vector<long long>(MAX);
    variable = vector<long long>(MAX, 0);
    int div;
    prime[0] = false;
    prime[1] = false;

    for (int i = MIN; i <= MAX; i++)
    {
        if (!prime[i])
            continue;
        factor[i] = i;
        expo[i] = 1;

        for (int j = MIN * i; j <= MAX; j += i)
        {
            prime[j] = false;
            factor[j] = i;
            div = j / i;
            if (factor[div] == i)
            {
                expo[j] = expo[div] + 1;
                variable[j] = variable[div];
            }
            else
            {
                expo[j] = 1;
                variable[j] = j / i;
            }
        }
    }
}

long long qtdDiv(long long i)
{
    if (variable[i] == 0)
        return expo[i] + 1;

    long long totalDiv = 1;
    while (variable[i] != 0)
    {
        totalDiv *= (expo[i] + 1);
        i = variable[i];
    }

    return totalDiv *= (expo[i] + 1);
}

vector<long long> qtdHip()
{
    vector<long long> qtd(MAX, 0);
    for (long long i = MIN; i <= MAX; i++)
    {
        qtd[i] = qtdDiv(i);
        qtd[i] = qtd[i - 1];
        if (prime[i])
        {
            qtd[i]++;
            continue;
        }
        long long qtdDiv_i = qtdDiv(i);
        if (prime[qtdDiv_i])
        {
            qtd[i]++;
        }
    }
    return qtd;
}

int main()
{
    _;
    crivo();
    vector<long long> qtd = qtdHip();

    long long n;

    while (cin >> n)
    {
        cout << qtd[n] << endl;
    }

    return 0;
}