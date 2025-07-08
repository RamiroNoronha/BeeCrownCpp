#include <bits/stdc++.h>
#define llu long long int
using namespace std;

// https://www.geeksforgeeks.org/convex-hull-monotone-chain-algorithm/
struct Point
{

    llu x, y;

    bool operator<(Point p)
    {
        return x < p.x || (x == p.x && y < p.y);
    }
};

llu cross_product(Point O, Point A, Point B)
{
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

vector<Point> convex_hull(vector<Point> A)
{
    int n = A.size(), k = 0;

    vector<Point> ans(2 * n);

    sort(A.begin(), A.end());

    for (int i = 0; i < n; ++i)
    {

        while (
            k >= 2 && cross_product(ans[k - 2], ans[k - 1], A[i]) <= 0)
            k--;
        ans[k++] = A[i];
    }

    for (size_t i = n - 1, t = k + 1; i > 0; --i)
    {

        while (k >= t && cross_product(ans[k - 2], ans[k - 1],
                                       A[i - 1]) <= 0)
            k--;
        ans[k++] = A[i - 1];
    }

    ans.resize(k - 1);

    return ans;
}

// https://www.mathopenref.com/coordpolygonarea.html
double area(vector<Point> &points)
{
    double area = 0.0;
    int n = points.size();
    for (int i = 0; i < n; i++)
    {
        int j = (i + 1) % n;
        area += points[i].x * points[j].y;
        area -= points[j].x * points[i].y;
    }
    return abs(area) / 2.0;
}

int main()
{
    vector<Point> points;
    double maxArea = 0.0;
    vector<vector<int>> combination = {
        {0, 1, 2, 3},
        {0, 1, 2, 4},
        {0, 1, 3, 4},
        {0, 2, 3, 4},
        {1, 2, 3, 4}};
    int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5;

    while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5)
    {
        if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0 &&
            x3 == 0 && y3 == 0 && x4 == 0 && y4 == 0 &&
            x5 == 0 && y5 == 0)
        {
            return 0;
        }
        points.clear();
        maxArea = 0.0;

        points.push_back({x1, y1});
        points.push_back({x2, y2});
        points.push_back({x3, y3});
        points.push_back({x4, y4});
        points.push_back({x5, y5});

        for (const auto &comb : combination)
        {
            vector<Point> temp;
            for (int idx : comb)
            {
                temp.push_back(points[idx]);
            }

            temp = convex_hull(temp);
            if (temp.size() == 4)
            {
                double newArea = area(temp);
                maxArea = max(maxArea, newArea);
            }
        }

        cout << fixed << setprecision(0) << maxArea << endl;
    }

    return 0;
}