#include <iostream>
#include <map>
#include <math.h>
using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

long long int comb(long long int n, long long int k)
{
    if (k > n)
        return 0;
    if (k == 0 || k == n)
        return 1;
    if (k == 1)
        return n;

    long long int res = 1;
    for (long long int i = 0; i < k; i++)
    {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

void accumulateDivisors(long long int &N, long long int i, long long int &count, long long int raiz, bool &found)
{
    while ((N % i) == 0)
    {
        N /= i;

        if (found)
        {
            count++;
            found = false;
        }
    }
}

int main()
{
    long long int N;
    cin >> N;
    long long int count = 0;
    long long int i = 2;
    long long int raiz = sqrt(N) + 1;
    bool found = true;
    accumulateDivisors(N, i, count, raiz, found);
    i++;
    while (N != 1 && i < raiz)
    {
        found = true;
        accumulateDivisors(N, i, count, raiz, found);

        i += 2;
    }
    if (N > 1)
    {
        count++;
    }

    if (count >= 2)
    {
        long long int result = 0;
        for (long long int i = 2; i <= count; i++)
        {
            result += comb(count, i);
        }
        cout << result << endl;
    }
    else
    {
        cout << 0 << endl;
    }
    return 0;
}