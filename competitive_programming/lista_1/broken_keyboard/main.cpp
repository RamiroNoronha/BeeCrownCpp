#include <iostream>
#include <string>
#include <set>
#include <queue>
#include <map>
using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

int main()
{
    int m;
    string input;

    while (true)
    {
        cin >> m;
        if (m == 0)
            return 0;
        cin.ignore(); // Ignora o caractere de nova linha deixado pelo cin anterior
        getline(cin, input);

        set<char> keys;
        map<char, int> freq;

        queue<char> q;
        int k = 0;
        int maxValue = 0;
        // cout << input << endl;
        for (int i = 0; i < input.length(); i++)
        {

            if (keys.size() < m)
            {

                freq[input[i]]++;
                k++;
                if (keys.find(input[i]) == keys.end())
                {
                    // cout << "new input: " << input[i] << endl;
                    q.push(input[i]);
                    keys.insert(input[i]);
                }
            }
            else if (keys.size() == m && keys.find(input[i]) != keys.end())
            {
                freq[input[i]]++;
                k++;
            }
            else
            {
                char letterToRemove = q.front();
                q.pop();
                keys.erase(letterToRemove);
                maxValue = max(maxValue, k);
                k -= freq[letterToRemove];
                freq[letterToRemove] = 0;
                i--;
                // cout << "i: " << i << " letterToRemove: " << letterToRemove << endl;
            }
        }

        cout << maxValue << endl;
    }
}