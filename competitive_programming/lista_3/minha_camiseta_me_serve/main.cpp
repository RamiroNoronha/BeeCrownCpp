#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define logs false
using namespace std;

struct Dinitz
{
    struct Edge
    {
        int to, rev;
        long long capacity;
    };

    int n;

    vector<vector<Edge>> graph;
    vector<int> level, iter;

    Dinitz(int n) : n(n), graph(n), level(n), iter(n) {}
    void add_edge(int from, int to, long long capacity)
    {
        graph[from].push_back({to, (int)graph[to].size(), capacity});
        graph[to].push_back({from, (int)graph[from].size() - 1, 0});
    }

    bool bsf(int s)
    {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        level[s] = 0;
        q.push(s);
        int v;
        while (!q.empty())
        {
            v = q.front();
            q.pop();

            for (const auto &e : graph[v])
            {
                if (e.capacity > 0 && level[e.to] < 0)
                {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }

        return level[n - 1] != -1;
    }

    int dfs(int v, int t, long long int flow)
    {
        if (v == t)
            return flow;
        for (int &i = iter[v]; i < (int)graph[v].size(); i++)
        {
            Edge &e = graph[v][i];
            if (e.capacity > 0 && level[e.to] == level[v] + 1)
            {
                int d = dfs(e.to, t, min(flow, e.capacity));
                if (d > 0)
                {
                    e.capacity -= d;
                    graph[e.to][e.rev].capacity += d;
                    return d;
                }
            }
        }
        return 0;
    }

    long long max_flow(int s, int t)
    {
        long long flow = 0;
        while (bsf(s))
        {
            fill(iter.begin(), iter.end(), 0);
            int f;
            while ((f = dfs(s, t, INF)) > 0)
            {
                flow += f;
            }
        }
        return flow;
    }
};

int main()
{
    _;
    string size1, size2;
    int q, N, M, S, T, V, size1_index, size2_index, qtd_shirts;
    cin >> q;
    map<string, int> size_to_index;

    while (q--)
    {
        cin >> N >> M;
        V = M + 8;
        qtd_shirts = N / 6;
        Dinitz dinitz(V);
        S = 0;
        T = M + 7;

        size_to_index["XS"] = M + 1;
        size_to_index["S"] = M + 2;
        size_to_index["M"] = M + 3;
        size_to_index["L"] = M + 4;
        size_to_index["XL"] = M + 5;
        size_to_index["XXL"] = M + 6;

        for (int i = 1; i <= M; i++)
        {
            cin >> size1 >> size2;
            size1_index = size_to_index[size1];
            size2_index = size_to_index[size2];
            dinitz.add_edge(S, i, 1);
            dinitz.add_edge(i, size1_index, INF);
            dinitz.add_edge(i, size2_index, INF);
        }

        for (const auto &item : size_to_index)
        {
            dinitz.add_edge(item.second, T, qtd_shirts);
        }

        string output = dinitz.max_flow(S, T) >= M ? "YES" : "NO";

        cout << output << endl;
    }

    return 0;
}