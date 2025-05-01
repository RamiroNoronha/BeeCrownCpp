#include <iostream>
#include <vector>

using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

vector<int> to_bend(vector<int> v, int pos)
{
    vector<int> res;
    for (int i = v.size() - 1; i >= pos; i--)
    {
        res.push_back(v[i]);
    }

    for (int i = res.size() - 1, j = pos - 1; j >= 0 && i >= 0; j--, i--)
    {
        res[i] += v[j];
    }

    return res;
}

vector<int> inverter(vector<int> v)
{
    vector<int> res;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        res.push_back(v[i]);
    }
    return res;
}

int get_max(vector<int> v)
{
    int max = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > max)
        {
            max = v[i];
        }
    }
    return max;
}

bool verify_vectors(vector<int> v, vector<int> w)
{

    if (v.size() != w.size())
    {
        return false;
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] != w[i])
        {
            return false;
        }
    }
    return true;
}

bool invalid_vector(vector<int> &v, int max)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > max)
        {
            return true;
        }
    }
    return false;
}

bool verify_sum(vector<int> v, vector<int> w)
{
    int sum_v = 0;
    int sum_w = 0;
    for (int i = 0; i < v.size(); i++)
    {
        sum_v += v[i];
    }
    for (int i = 0; i < w.size(); i++)
    {
        sum_w += w[i];
    }
    return sum_v == sum_w;
}

bool check(vector<int> v, vector<int> w, int max, int pos = 0)
{

    if (invalid_vector(v, max))
    {
        return false;
    }
    if (pos > v.size() / 2 + 1)
    {
        return false;
    }

    if (v.size() < w.size())
        return false;

    bool isPossible = verify_vectors(v, w);
    if (isPossible)
        return true;

    for (int i = 0; i < v.size() / 2 + 1; i++)
    {
        if (check(to_bend(v, pos + i), w, max, i == 0 ? pos + 1 : pos))
            return true;
    }
    return false;
}

int main()
{
    int N;
    while (cin >> N)
    {
        vector<int> v(N);
        for (int i = 0; i < N; i++)
        {
            cin >> v[i];
        }

        int M;
        cin >> M;
        vector<int> w(M);
        for (int i = 0; i < M; i++)
        {
            cin >> w[i];
        }

        bool isNotPossible = !verify_sum(v, w);
        if (isNotPossible)
        {
            cout << "N" << endl;
            continue;
        }
        int max = get_max(w);

        check(v, w, max) ? cout << "S" << endl : cout << "N" << endl;
    }

    return 0;
}