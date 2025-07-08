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
    int N, M, K;
    vector<int> houselimit;
    vector<vector<int>> horseAfinity;
    int itr = 1;
    int u, v;
    int source, sink, c;
    while (cin >> N >> M >> K)
    {
        source = 0;
        sink = N + M + 1;
        Dinitz dinitz(N + M + 2);
        for (int i = 1; i <= N; i++)
        {
            cin >> c;
            dinitz.add_edge(source, i, c);
        }

        for (int i = 0; i < K; i++)
        {
            cin >> u >> v;
            dinitz.add_edge(u, v + N, INF);
        }

        for (int i = 1; i <= M; i++)
            dinitz.add_edge(i + N, sink, 1);

        long long flow = dinitz.max_flow(0, N + M + 1);
        cout << "Instancia " << itr++ << endl;
        cout << flow << endl;
    }
    return 0;
}