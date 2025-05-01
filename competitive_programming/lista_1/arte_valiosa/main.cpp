#include <iostream>
#include <vector>
#include <string>
#include <tuple>
using namespace std;
#define INF 0x3f3f3f3f
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define logs false

struct Camera
{
    int x;
    int y;
    int r;
};
int findSet(int v, vector<int> &parents)
{
    if (v == parents[v])
    {
        return v;
    }

    return parents[v] = findSet(parents[v], parents);
}
void unionSets(int a, int b, vector<int> &parents, vector<int> &rank, vector<vector<int>> &children)
{
    a = findSet(a, parents);
    b = findSet(b, parents);

    if (a == b)
        return;

    if (rank[a] < rank[b])
    {
        swap(a, b);
    }
    parents[b] = a;
    children[a].push_back(b);
    children[b].clear();
    if (rank[a] == rank[b])
    {
        rank[a]++;
    }
}

int main()
{
    int M, N, K;

    cin >> M >> N >> K;

    pair<int, int> p1, p2;

    p1 = make_pair(0, 0);
    p2 = make_pair(M, N);

    vector<Camera> v;
    vector<int> parents(N + 1);
    vector<int> rank(N);
    vector<bool> used(N + 1, false);
    vector<vector<int>> children(N + 1);
    for (int i = 0; i < K; i++)
    {
        int x, y, r;
        cin >> x >> y >> r;
        parents[i] = i;
        children[i].push_back(i);
        rank[i] = 0;
        v.push_back({x, y, r});
    }

    for (int i = 0; i < K; i++)
    {
        for (int j = i + 1; j < K; j++)
        {
            int dx = v[i].x - v[j].x;
            int dy = v[i].y - v[j].y;
            long int dist = dx * dx + dy * dy;
            long int radii = (long int)(v[i].r + v[j].r);
            if (dist <= radii * radii)
            {
                unionSets(i, j, parents, rank, children);
            }
        }
    }

    for (int i = 0; i < K; i++)
    {
        int a = findSet(i, parents);

        if (logs)
            cout << "Camera " << i << " is in set " << a << endl;
    }

    for (int i = 0; i < K; i++)
    {
        int set = findSet(i, parents);

        if (used[set])
            continue;
        used[set] = true;
        int xs = INF, ys = INF, xe = -INF, ye = -INF;
        for (auto child : children[set])
        {
            xs = min(xs, v[child].x - v[child].r);
            ys = min(ys, v[child].y - v[child].r);
            xe = max(xe, v[child].x + v[child].r);
            ye = max(ye, v[child].y + v[child].r);
        }

        if (xs <= 0 && ys <= 0)
        {
            if (logs)
            {
                cout << "COND 2" << endl;
                cout << "set " << set << endl;
                cout << "xs " << xs << endl;
                cout << "ys " << ys << endl;
            }
            cout << "N" << endl;
            return 0;
        }

        if (xe >= M && ye >= N)
        {
            if (logs)
            {
                cout << "COND 3" << endl;
                cout << "set " << set << endl;
                cout << "xe " << xe << endl;
                cout << "ye " << ye << endl;
                cout << "M value " << M << endl;
                cout << "N value " << N << endl;
            }
            cout << "N" << endl;
            return 0;
        }

        xe = min(xe, M);
        ye = min(ye, N);
        xs = max(xs, 0);
        ys = max(ys, 0);

        if (xe - xs >= M || ye - ys >= N)
        {
            if (logs)
            {
                cout << "COND 1" << endl;
                cout << "set " << set << endl;
                cout << "xs " << xs << endl;
                cout << "ys " << ys << endl;
                cout << "xe " << xe << endl;
                cout << "ye " << ye << endl;
                cout << "xe - xs: " << xe - xs << endl;
                cout << "ye - ys: " << ye - ys << endl;
                cout << "M value " << M << endl;
                cout << "N value " << N << endl;
            }
            cout << "N" << endl;
            return 0;
        }
    }
    cout << "S" << endl;
    return 0;
}