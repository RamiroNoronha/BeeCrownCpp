#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <string>
using namespace std;
#define INF 0x3f3f3f3f
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define logs false

int main()
{
    int t;
    string input;
    cin >> t;
    vector<int> v;
    int menor, maior;

    while (t--)
    {
        cin >> maior;
        cin >> input;
        menor = 1;
        v.resize(maior, 1);

        if (logs)
        {
            cout << "input: " << input << endl;
            cout << "maior: " << maior << endl;
            for (int i = 0; i < v.size(); i++)
            {
                cout << v[i] << " ";
            }
            cout << "----" << endl;
        }

        for (int i = maior - 2; i >= 0; i--)
        {
            if (input[i] == '<')
            {
                v[i + 1] = menor;
                menor++;
            }
            else
            {
                v[i + 1] = maior;
                maior--;
            }
        }

        v[0] = max(menor, maior);

        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
}