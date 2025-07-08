#include <bits/stdc++.h>

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

#define MOD 1000000
using namespace std;
using lli = long long;

void multiply(vector<vector<lli>> &a, vector<vector<lli>> &b)
{
    vector<vector<lli>> res = vector<vector<lli>>(a.size(), vector<lli>(b[0].size(), 0));
    for (lli i = 0; i < a.size(); i++)
        for (lli j = 0; j < b[0].size(); j++)
            for (lli k = 0; k < a[0].size(); k++)
                res[i][j] += (((a[i][k] % MOD) * (b[k][j] % MOD)) % MOD);

    a = res;
}

void power(vector<vector<lli>> &a, lli n)
{
    lli K = a.size();
    vector<vector<lli>> res(K, vector<lli>(K, 0));
    for (lli i = 0; i < K; i++)
    {
        res[i][i] = 1;
    }

    vector<vector<lli>> pot = a;

    while (n)
    {
        if (n % 2 == 1)
        {
            multiply(res, pot);
        }
        multiply(pot, pot);
        n /= 2;
    }
    a = res;
}

std::vector<lli> multiply_v_mat(const std::vector<std::vector<lli>> &mat, const std::vector<lli> &v)
{
    size_t n = v.size();

    std::vector<lli> resultado(n, 0);

    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < n; ++j)
        {
            resultado[i] += ((mat[i][j] % MOD) * (v[j] % MOD)) % MOD;
        }
    }

    return resultado;
}

int main()
{
    _;
    lli N, K, L, x, f1, f2;
    while (cin >> N >> K >> L)
    {
        K %= MOD;
        L %= MOD;
        vector<vector<lli>> mat(2, vector<lli>(2, 0));
        mat[0][0] = K;
        mat[0][1] = L;
        mat[1][0] = 1;
        mat[1][1] = 0;

        x = N / 5;

        power(mat, x - 1);
        f1 = K;
        f2 = 1;
        vector<lli> v(2, 0);
        v[0] = f1;
        v[1] = f2;
        vector<lli> res = multiply_v_mat(mat, v);
        cout << std::setw(6) << std::setfill('0') << res[0] % MOD << endl;
    }
    return 0;
}