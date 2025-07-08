#include <bits/stdc++.h>

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
using namespace std;
using lli = long long;

// https://www.geeksforgeeks.org/convex-hull-monotone-chain-algorithm/
struct Point
{
    int x, y;

    bool operator==(const Point &t) const
    {
        return x == t.x && y == t.y;
    }
    bool operator<(const Point &t) const
    {
        return x < t.x || (x == t.x && y < t.y);
    }
};

int cross_product(Point O, Point A, Point B)
{
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

void convex_hull(vector<Point> &A)
{
    int n = A.size(), k = 0;

    if (n < 3)
        return;

    vector<Point> ans(2 * n);

    sort(A.begin(), A.end());

    for (int i = 0; i < n; ++i)
    {

        while (
            k >= 2 && cross_product(ans[k - 2], ans[k - 1], A[i]) < 0)
            k--;
        ans[k++] = A[i];
    }

    for (size_t i = n - 1, t = k + 1; i > 0; --i)
    {

        while (k >= t && cross_product(ans[k - 2], ans[k - 1],
                                       A[i - 1]) < 0)
            k--;
        ans[k++] = A[i - 1];
    }

    ans.resize(k - 1);

    for (Point p : ans)
    {
        auto it = find(A.begin(), A.end(), p);
        A.erase(it);
    }
}

int main()
{
    _;

    int n, k;

    while (cin >> n && n)
    {
        k = 0;
        vector<Point> points(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> points[i].x >> points[i].y;
        }
        while (points.size() > 2)
        {
            convex_hull(points);
            k++;
        }

        if (k % 2 == 0)
            cout << "Do not take this onion to the lab!" << endl;

        else
            cout << "Take this onion to the lab!" << endl;
    }

    return 0;
}