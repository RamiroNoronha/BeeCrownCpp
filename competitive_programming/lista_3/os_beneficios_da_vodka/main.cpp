#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define logs false
using namespace std;

int N, M;
vector<vector<int>> rGraph;
vector<int> parent;

bool bfs(int s, int t)
{
    int V = N + M + 2; // Total vertices including source and sink
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && rGraph[u][v] > 0)
            {
                if (v == t)
                {
                    parent[v] = u;
                    return true;
                }

                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return false;
}

int fordFulkerson(int s, int t)
{
    int u, v;
    int max_flow = 0;

    while (bfs(s, t))
    {
        int path_flow = INF;
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main()
{
    while (cin >> N >> M)
    {
        rGraph = vector<vector<int>>(N + M + 2, vector<int>(N + M + 2, 0));
        parent = vector<int>(N + M + 2, 0);
        vector<int> categories(M);
        int s = 0;
        int t = N + M + 1;
        int c, p;
        int sum = 0;
        for (int i = 1; i <= N; i++)
            cin >> rGraph[i][t];

        for (int i = 1; i <= M; i++)
            cin >> categories[i - 1];

        for (int i = N + 1; i <= N + M; i++)
        {
            cin >> p;
            sum += p;
            rGraph[s][i] = p;
            for (int j = 0; j < categories[i - N - 1]; j++)
            {
                int v;
                cin >> v;
                rGraph[i][v] = INF;
            }
        }

        cout << sum - fordFulkerson(s, t) << endl;
    }
}