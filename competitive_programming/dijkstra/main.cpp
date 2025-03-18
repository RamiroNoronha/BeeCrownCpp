#include <iostream>
#include <string>
#include <set>

using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

int main()
{
    set<string> jewelry;
    string jewel;

    while (cin >> jewel)
    {
        jewelry.insert(jewel);
    }

    cout << jewelry.size() << endl;
    return 0;
}