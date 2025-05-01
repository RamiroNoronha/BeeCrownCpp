#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

int findSet(int v, vector<int> &parents)
{
    if (v == parents[v])
        return v;

    return parents[v] = findSet(parents[v], parents);
}

void unionSets(int a, int b, vector<int> &parents, vector<int> &rank)
{
    a = findSet(a, parents);
    b = findSet(b, parents);

    if (a != b)
    {
        if (rank[a] < rank[b])
        {
            swap(a, b);
        }
        parents[b] = a;
        if (rank[a] == rank[b])
        {
            rank[a]++;
        }
    }
}

void initializeParents(vector<int> &parents, int N)
{
    for (int i = N; i >= 0; i--)
    {
        parents[i] = i;
    }
}

void initializeRanks(vector<int> &rank, int N)
{
    for (int i = 0; i < N; i++)
    {
        rank.push_back(0);
    }
}

void kruskal(vector<tuple<int, int, int>> &v, vector<tuple<int, int, int>> &mst, vector<int> &parents, vector<int> &rank, int N)
{
    for (int i = 0; i < N; i++)
    {
        if (findSet(get<0>(v[i]), parents) != findSet(get<1>(v[i]), parents))
        {
            mst.push_back(v[i]);
            unionSets(get<0>(v[i]), get<1>(v[i]), parents, rank);
        }
    }
}

int sumMst(vector<tuple<int, int, int>> &mst)
{
    int sum = 0;
    for (auto e : mst)
    {
        sum += get<2>(e);
    }
    return sum;
}

int main()
{

    int N;
    cin >> N;

    vector<tuple<int, int, int>> v;
    vector<tuple<int, int, int>> mst;
    vector<tuple<int, int, int>> mstMax;

    vector<int> parents(N + 1);
    vector<int> rank(N, 0);

    initializeParents(parents, N);

    for (int i = 0; i < N; i++)
    {
        int e1, e2, w;
        cin >> e1 >> e2 >> w;
        v.push_back(make_tuple(e1, e2, w));
    }

    sort(v.begin(), v.end(), [](tuple<int, int, int> a, tuple<int, int, int> b)
         { return get<2>(a) < get<2>(b); });

    kruskal(v, mst, parents, rank, N);

    int valueMin = sumMst(mst);

    sort(v.begin(), v.end(), [](tuple<int, int, int> a, tuple<int, int, int> b)
         { return get<2>(a) > get<2>(b); });

    initializeParents(parents, N);
    initializeRanks(rank, N);

    kruskal(v, mstMax, parents, rank, N);

    int valueMax = sumMst(mstMax);

    cout << valueMax << endl
         << valueMin << endl;

    return 0;
}