#include <iostream>
#include <vector>
#include <queue>
#include <numeric>

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

int N,
    M;
vector<vector<int>> rGraph;
vector<int> parent;

int main()
{
    _;

    while (cin >> N >> M)
    {
        int num_vertices = N + M + 2;
        Dinitz dinitz(num_vertices);
        int s = 0;
        int t = num_vertices - 1;

        vector<int> categories_quantities(M);
        long long sum = 0;

        for (int i = 1; i <= N; i++)
        {
            int cost;
            cin >> cost;
            dinitz.add_edge(i, t, cost);
        }

        for (int i = 0; i < M; i++)
            cin >> categories_quantities[i];

        for (int i = 0; i < M; i++)
        {
            int benefit;
            cin >> benefit;

            int category_node = N + 1 + i;

            sum += benefit;
            dinitz.add_edge(s, category_node, benefit);

            for (int j = 0; j < categories_quantities[i]; j++)
            {
                int vodka_type;
                cin >> vodka_type;
                dinitz.add_edge(category_node, vodka_type, INF);
            }
        }

        cout << sum - dinitz.max_flow(s, t) << endl;
    }
    return 0;
}
