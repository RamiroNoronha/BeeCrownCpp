#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define logs true
using namespace std;

struct FlowResult
{
    long long max_flow = 0;
    vector<pair<long long int, long long int>> paths_and_lengths;
};

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

    int bsf(int s)
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

        return level[n - 1];
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

    FlowResult max_flow(int s, int t)
    {
        long long flow = 0;
        long long int level, metric;
        vector<pair<long long int, long long int>> paths_and_lengths;
        while ((level = bsf(s)) != -1)
        {
            metric = 0;
            fill(iter.begin(), iter.end(), 0);
            int f;
            while ((f = dfs(s, t, INF)) > 0)
            {
                metric += f;
            }
            flow += metric;
            paths_and_lengths.push_back({metric, level - 1});
        }
        return {flow, paths_and_lengths};
    }
};

int main()
{
    _;
    int N, M, A;
    int O, D, S;
    while (cin >> N >> M >> A && (N || M || A))
    {
        Dinitz flow(N + 1);
        int source = 0;

        flow.add_edge(source, 1, A);
        for (int i = 0; i < M; ++i)
        {
            cin >> O >> D >> S;
            flow.add_edge(O, D, S);
        }

        FlowResult result = flow.max_flow(source, N);
        long long int days = 0, flowNew = 0;
        while (true)
        {

            for (const auto &path : result.paths_and_lengths)
            {
                if (path.second > days)
                    continue;

                flowNew += path.first;
            }
            if (flowNew >= A)
                break;

            days++;
        }

        cout << days << endl;
    }
    return 0;
}
