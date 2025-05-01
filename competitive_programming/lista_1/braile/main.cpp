#include <iostream>
#include <map>
#include <string>

using namespace std;
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

map<string, string> createMapBraille()
{
    map<string, string> braille;
    // Number to braille
    braille["0-0"] = ".*";
    braille["0-1"] = "*.";
    braille["0-2"] = "*.";
    braille["0-3"] = "**";
    braille["0-4"] = "**";
    braille["0-5"] = "*.";
    braille["0-6"] = "**";
    braille["0-7"] = "**";
    braille["0-8"] = "*.";
    braille["0-9"] = ".*";
    braille["1-0"] = "**";
    braille["1-1"] = "..";
    braille["1-2"] = "*.";
    braille["1-3"] = "..";
    braille["1-4"] = ".*";
    braille["1-5"] = ".*";
    braille["1-6"] = "*.";
    braille["1-7"] = "**";
    braille["1-8"] = "**";
    braille["1-9"] = "*.";
    braille["2-0"] = "..";
    braille["2-1"] = "..";
    braille["2-2"] = "..";
    braille["2-3"] = "..";
    braille["2-4"] = "..";
    braille["2-5"] = "..";
    braille["2-6"] = "..";
    braille["2-7"] = "..";
    braille["2-8"] = "..";
    braille["2-9"] = "..";

    // brailer to number
    braille[".***.."] = "0";
    braille["*....."] = "1";
    braille["*.*..."] = "2";
    braille["**...."] = "3";
    braille["**.*.."] = "4";
    braille["*..*.."] = "5";
    braille["***..."] = "6";
    braille["****.."] = "7";
    braille["*.**.."] = "8";
    braille[".**..."] = "9";
    return braille;
}

int main()
{
    map<string, string> braille = createMapBraille();

    int D;

    while (cin >> D)
    {
        if (D == 0)
            break;

        char type;
        cin >> type;

        if (type == 'S')
        {
            string entry;
            cin >> entry;

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < entry.length(); j++)
                {
                    cout << braille[to_string(i) + "-" + entry[j]] << " ";
                }

                cout << endl;
            }
        }

        if (type == 'B')
        {
            string brailleEntry[D];
            string line;

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < D; j++)
                {
                    cin >> line;
                    brailleEntry[j] += line;
                }
            }

            for (int i = 0; i < D; i++)
            {
                cout << braille[brailleEntry[i]];
            }

            cout << endl;
        }
    }
    return 0;
}