#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define INF 0x3f3f3f3f

int main()
{

    int N, M, K;
    double P;
    while (cin >> N >> M >> K >> P)
    {
        vector<pair<int, double>> adj[N];
        for (int i = 0; i < M; i++)
        {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            adj[u].push_back({v, 0});
            adj[v].push_back({u, 0});
        }

        int A;
        cin >> A;
        // cout << 3 << endl;
        for (int i = 0; i < A; i++)
        {
            int u;
            cin >> u;
            u--;
            for (auto &edge : adj[u])
            {
                edge.second++;
            }
        }

        int start, end;
        cin >> start >> end;
        start--;
        end--;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
            pq;
        vector<int> dist(N, INF);

        pq.push({0, start});
        dist[start] = 0;
        // cout << 4 << endl;
        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            for (auto &edge : adj[u])
            {
                int v = edge.first;
                double weight = edge.second;
                if (dist[v] > dist[u] + weight)
                {
                    dist[v] = dist[u] + weight;

                    pq.push({dist[v], v});
                }
            }
        }
        // cout << 5 << endl;
        dist[end] += adj[end].size() == 0 ? K + 1 : adj[end][0].second;
        cout << fixed << setprecision(3);
        if (dist[end] > K)
        {
            cout << 0.000 << endl;
            continue;
        }
        double result = 1;
        for (int i = 0; i < dist[end]; i++)
        {
            result *= P;
        }

        cout << result << endl;
    }

    return 0;
}