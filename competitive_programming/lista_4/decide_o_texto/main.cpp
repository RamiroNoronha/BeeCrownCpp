#include <bits/stdc++.h>

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
using namespace std;
using lli = long long;

void multiply(vector<vector<lli>> &a, vector<vector<lli>> &b)
{
    vector<vector<lli>> res = vector<vector<lli>>(a.size(), vector<lli>(b[0].size(), 0));
    for (lli i = 0; i < a.size(); i++)
        for (lli j = 0; j < b[0].size(); j++)
            for (lli k = 0; k < a[0].size(); k++)
                res[i][j] += a[i][k] * b[k][j];

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
            resultado[i] += mat[i][j] * v[j];
        }
    }

    return resultado;
}

int main()
{
    _;
    lli n, m, k;
    while (cin >> n >> m && (n || m))
    {
        vector<vector<lli>> mat(n, vector<lli>(n, 0));
        vector<lli> v(n, 0);
        vector<lli> perm(n, 0);
        string ans(n, ' ');
        for (int i = 0; i < n; i++)
        {
            cin >> k;
            perm[i] = k - 1;
            v[perm[i]] = i;
        }
        for (int i = 0; i < n; i++)
        {
            mat[i][v[i]] = 1;
        }

        string texto;
        cin.ignore();
        getline(cin, texto);

        power(mat, m);

        vector<lli> result = multiply_v_mat(mat, v);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 1)
                {
                    ans[i] = texto[j];
                    break;
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}