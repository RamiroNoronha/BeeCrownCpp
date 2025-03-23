#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

int main()
{

    string line;
    string crib;

    while (cin >> line)
    {
        cin >> crib;

        int lengthLine = line.length();
        int lengthCrib = crib.length();
        int diff = lengthLine - lengthCrib + 1;

        map<char, set<int>> cribPositions;
        set<int> allAvailablePositions = set<int>();

        for (int i = 0; i < lengthCrib; i++)
        {
            cribPositions[crib[i]] = set<int>();
        }

        for (int i = 0; i < lengthLine; i++)
        {
            if (cribPositions.find(line[i]) != cribPositions.end())
            {
                cribPositions[line[i]].insert(i);
            }
            if (i < diff)
            {
                allAvailablePositions.insert(i);
            }
        }

        for (int i = 0; i < lengthCrib; i++)
        {
            set<int> positionsForLetter = cribPositions[crib[i]];
            for (auto it = positionsForLetter.begin(); it != positionsForLetter.end(); it++)
            {
                allAvailablePositions.erase(*it - i);
            }
        }

        cout << allAvailablePositions.size() << endl;
    }

    return 0;
}