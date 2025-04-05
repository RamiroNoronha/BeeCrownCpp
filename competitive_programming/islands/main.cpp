#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 0x3f3f3f3f

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

int main()
{
    int N, M;

    cin >> N >> M;

    vector<vector<pair<int, int>>> adj(N, vector<pair<int, int>>());

    for (int i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int server;
    cin >> server;
    server--;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
        pq;
    vector<int> dist(N, INF);

    pq.push({0, server});
    dist[server] = 0;
    // int lower = INF;
    // int maxValue = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (auto &edge : adj[u])
        {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                // if (v != server)
                // {
                //     lower = min(lower, dist[v]);
                //     maxValue = max(maxValue, dist[v]);
                // }
                pq.push({dist[v], v});
            }
        }
    }
    int lower = INF;
    int max = 0;
    for (int i = 0; i < N; i++)
    {
        if (i == server)
            continue;
        if (dist[i] < lower)
        {
            lower = dist[i];
        }
        if (dist[i] > max)
        {
            max = dist[i];
        }
    }
    cout << max - lower << endl;
}