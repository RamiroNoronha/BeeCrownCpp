#include <string>
#include <iostream>
#include <set>

using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

void find_pos_fix(string prefix, string infix, string &posfix, set<char> &vertices)
{
    char firstLetter = prefix[0];

    int lastPosition = posfix.rfind('_');
    if (lastPosition != -1 && firstLetter != '\0' && vertices.find(firstLetter) != vertices.end())
    {
        vertices.erase(firstLetter);
        posfix[lastPosition] = firstLetter;

        int firstLetterIndex = infix.find(firstLetter);

        string newPrefix;
        string newInfix;
        if (firstLetterIndex + 1 < prefix.size())
        {
            newPrefix = prefix.substr(firstLetterIndex + 1, prefix.size());
            newInfix = infix.substr(firstLetterIndex + 1, infix.size());
        }
        else if (prefix.size() > 1)
        {
            newPrefix = prefix.substr(1, prefix.size());
            newInfix = infix.substr(0, firstLetterIndex);
        }

        find_pos_fix(newPrefix, newInfix, posfix, vertices);

        if (firstLetterIndex > 0)
        {
            newPrefix = prefix.substr(1, firstLetterIndex);
            newInfix = infix.substr(0, firstLetterIndex);

            find_pos_fix(newPrefix, newInfix, posfix, vertices);
        }
    }
}

int main()
{
    int entries_quantity;

    cin >> entries_quantity;

    for (int i = 0; i < entries_quantity; i++)
    {
        string prefix, infix, posfix;
        set<char> vertices;
        int vertices_quantity;

        cin >> vertices_quantity >> prefix >> infix;

        for (int j = 0; j < vertices_quantity; j++)
        {
            posfix += '_';
            vertices.insert(infix[j]);
        }

        find_pos_fix(prefix, infix, posfix, vertices);

        cout << posfix << endl;
    }
}