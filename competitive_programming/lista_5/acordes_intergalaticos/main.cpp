#include <bits/stdc++.h>

#define _                             \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

#define INF 1000000000
#define SCORE 9
using namespace std;
using lli = long long;

struct No
{
    array<int, SCORE> freq = {};
    int lazy = 0;
};

vector<No> tree;
vector<int> v;

void merge(No &father, const No &leftChild, const No &rightChild)
{
    for (int i = 0; i < SCORE; ++i)
    {
        father.freq[i] = leftChild.freq[i] + rightChild.freq[i];
    }
}

void push(int node, int start, int end)
{
    if (tree[node].lazy == 0)
        return;

    int delta = tree[node].lazy % SCORE;
    if (delta == 0)
    {
        tree[node].lazy = 0;
        return;
    }

    array<int, SCORE> new_frequency = {};
    for (int i = 0; i < SCORE; ++i)
    {
        if (tree[node].freq[i] > 0)
        {
            int new_value = (i + delta) % SCORE;
            new_frequency[new_value] += tree[node].freq[i];
        }
    }
    tree[node].freq = new_frequency;

    if (start != end)
    {
        tree[2 * node].lazy += delta;
        tree[2 * node + 1].lazy += delta;
    }
    tree[node].lazy = 0;
}

void build(int node, int start, int end)
{
    if (start == end)
    {
        tree[node].freq[v[start]] = 1;
        return;
    }

    int mid = start + (end - start) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    merge(tree[node], tree[2 * node], tree[2 * node + 1]);
}

void range_update(int node, int start, int end, int l, int r, int val)
{
    push(node, start, end);
    if (start > r || end < l)
    {
        return;
    }
    if (start >= l && end <= r)
    {
        tree[node].lazy += val;
        push(node, start, end);
        return;
    }
    int mid = start + (end - start) / 2;
    range_update(2 * node, start, mid, l, r, val);
    range_update(2 * node + 1, mid + 1, end, l, r, val);

    merge(tree[node], tree[2 * node], tree[2 * node + 1]);
}

No query(int node, int start, int end, int l, int r)
{
    if (start > r || end < l)
    {
        return No();
    }
    push(node, start, end);
    if (start >= l && end <= r)
    {
        return tree[node];
    }
    int mid = start + (end - start) / 2;
    No leftChild = query(2 * node, start, mid, l, r);
    No rightChild = query(2 * node + 1, mid + 1, end, l, r);

    No result;
    merge(result, leftChild, rightChild);
    return result;
}

int encontrarModa(const No &no)
{
    int moda_valor = -1;
    int moda_frequencia = -1;
    for (int i = 0; i < SCORE; ++i)
    {
        if (no.freq[i] >= moda_frequencia)
        {
            moda_frequencia = no.freq[i];
            moda_valor = i;
        }
    }
    return moda_valor;
}

int main()
{
    _;
    int n, m;
    while (cin >> n >> m)
    {
        v.assign(n, 1);
        tree.assign(4 * n + 4, No());

        vector<pair<int, int>> chords(m);
        for (int i = 0; i < m; i++)
        {
            cin >> chords[i].first >> chords[i].second;
        }

        build(1, 0, n - 1);

        for (int i = 0; i < m; i++)
        {
            int left = chords[i].first;
            int right = chords[i].second;

            No value = query(1, 0, n - 1, left, right);
            int moda = encontrarModa(value);

            if (moda != -1)
            {
                range_update(1, 0, n - 1, left, right, moda);
            }
        }

        for (int i = 0; i < n; i++)
        {
            No final_node = query(1, 0, n - 1, i, i);
            cout << encontrarModa(final_node) << "\n";
        }
    }
    return 0; 
}
