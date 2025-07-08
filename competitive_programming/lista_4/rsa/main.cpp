#include <bits/stdc++.h>

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
using namespace std;

// https://www.geeksforgeeks.org/dsa/eulers-totient-function/
long long phi(long long n)
{
    if (n < 2)
        return 0;

    long long result = n;
    for (long long i = 2; i * i <= n + 1; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

long long gcdEstendido(long long a, long long b, long long *x, long long *y)
{
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }

    long long x1, y1;
    long long gcd = gcdEstendido(b % a, a, &x1, &y1);

    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

long long modInverseEuclides(long long e, long long phi)
{
    long long x, y;
    long long g = gcdEstendido(e, phi, &x, &y);

    if (g != 1)
    {
        return -1;
    }

    return (x % phi + phi) % phi;
}

// https://www.geeksforgeeks.org/computer-networks/rsa-algorithm-cryptography/
long long power(long long base, long long expo, long long m)
{
    long long res = 1;
    base = base % m;
    while (expo > 0)
    {
        if (expo & 1)
            res = (res * 1LL * base) % m;
        base = (base * 1LL * base) % m;
        expo = expo / 2;
    }
    return res;
}

long long decrypt(long long c, long long d, long long n)
{
    return power(c, d, n);
}

int main()
{
    _;
    long long N, E, C;

    while (cin >> N >> E >> C)
    {
        long long phiN = phi(N);
        long long D = modInverseEuclides(E, phiN);
        long long M = decrypt(C, D, N);
        cout << M << endl;
    }

    return 0;
}