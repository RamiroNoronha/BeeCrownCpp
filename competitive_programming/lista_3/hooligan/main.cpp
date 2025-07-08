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
    int iter = 0;
    int N, M, G, I, J, rest, p_menor, p_maior, k, total;
    vector<int> t;
    vector<vector<int>> adj;
    char s;
    while (cin >> N >> M >> G && N && M && G)
    {
        iter++;
        if ((iter >= 48 && iter <= 100) && logs)
        {
            cout << "input n " << iter << ": " << N << " " << M << " " << G << endl;
        }
        rest = (N * (N - 1) / 2) * M;
        total = (rest - G) * 2;
        t.clear();
        t.resize(N);
        adj.clear();
        adj.assign(N, vector<int>(N, 0));
        if (logs)
        {
            cout << "total inicio: " << total << endl;
            cout << "t[0] inicio: " << t[0] << endl;
                }
        k = 1;

        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                adj[i][j] = M;
            }
        }
        for (int i = 0; i < G; i++)
        {

            cin >> I >> s >> J;
            p_menor = min(I, J);
            p_maior = max(I, J);
            adj[p_menor][p_maior]--;
            if (adj[p_menor][p_maior] == 0)
            {
                rest--;
            }
            if (s == '<')
            {
                t[J] += 2;
            }
            else if (s == '=')
            {
                t[I]++;
                t[J]++;
            }
        }

        for (int i = 0; i < N; i++)
        {
            if (logs)
            {
                cout << "t[" << i << "] = " << t[i] << endl;
            }
        }

        for (int i = 1; i < N; i++)
        {
            if (!adj[0][i])
                continue;
            t[0] += adj[0][i] * 2;
            rest--;
            total -= 2 * adj[0][i];
            adj[0][i] = 0;
        }

        if (logs)
        {
            cout << "rest: " << rest << endl;
            cout << "total: " << total << endl;
            cout << "t[0]: " << t[0] << endl;
        }
        Dinitz dinitz(N - 1 + rest + 2);
        bool failured = false;

        for (int i = 1; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                if (adj[i][j] > 0)
                {

                    dinitz.add_edge(0, k, adj[i][j] * 2);
                    dinitz.add_edge(k, rest + i, INF);
                    dinitz.add_edge(k, rest + j, INF);
                    if (t[0] - t[i] - 1 < 0 || t[0] - t[j] - 1 < 0)
                    {
                        failured = true;
                    }
                    dinitz.add_edge(rest + i, N + rest, t[0] - t[i] - 1);
                    dinitz.add_edge(rest + j, N + rest, t[0] - t[j] - 1);
                    if (logs)
                    {
                        cout << "t[0] - t[" << i << "] - 1 =  " << t[0] << " - " << t[i] << " - 1: " << t[0] - t[i] - 1 << endl;
                        cout << "t[0] - t[" << j << "] - 1 =  " << t[0] << " - " << t[j] << " - 1: " << t[0] - t[j] - 1 << endl;
                        cout << "(0, " << k << ") partida " << i << ", " << j << " -> " << adj[i][j] * 2 << endl;
                        cout << "(" << k << ", " << rest + i << ") INF " << endl;
                        cout << "(" << k << ", " << rest + j << ") INF " << endl;
                        cout << "(" << rest + i << ", " << N + rest << ") " << t[0] - t[i] - 1 << endl;
                        cout << "(" << rest + j << ", " << N + rest << ") " << t[0] - t[j] - 1 << endl;
                    }
                    k++;
                }
            }
        }
        long long int result = dinitz.max_flow(0, N + rest);
        if (logs)
        {
            cout << "result: " << result << endl;
            cout << "total: " << total << endl;
        }
        char resposta = result >= total && !failured ? 'Y' : 'N';
        cout << resposta << endl;
    }
}