#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

#define LIMITE 1000

bool verifySum(vector<int> numbers)
{
    int total = 0;
    for (int i = 0; i < numbers.size() - 1; i++)
        total += numbers[i];

    return total == numbers[numbers.size() - 1];
}

void incrementPositions(vector<int> &positions, int p)
{
    if (p + 1 == positions.size() && positions[p] == positions.size() - 1)
    {
        positions[p]++;
        return;
    }
    bool isValid = positions[p] + 1 < positions[p + 1] && (positions[p] - positions[max(p - 1, 0)]) < 4;
    if (isValid)
    {
        positions[p]++;
        return;
    }

    incrementPositions(positions, p + 1);
}

vector<int> numbers(string number, int count)
{
    int numbersQuantity = count + 1;
    vector<int> result;
    vector<int> positions(numbersQuantity, 0);

    int initialDivider = number.size() / numbersQuantity;
    // cout << number << endl;
    positions[0] = 0;

    for (int i = 1; i < numbersQuantity; i++)
    {
        positions[i] = positions[i - 1] + initialDivider;
        // cout << positions[i] << " ";
    }
    // cout << endl;

    while (true)
    {
        // cout << "Positions: ";
        // for (int i = 0; i < count + 1; i++)
        //     cout << positions[i] << " ";
        // cout << endl;
        for (int i = 0; i < numbersQuantity; i++)
        {
            bool lastPosition = i == count;
            string partNumber = number.substr(positions[i], lastPosition ? string::npos : positions[i + 1] - positions[i]);
            result.push_back(stoi(partNumber));
        }

        // cout << "Result: ";
        // for (int i = 0; i < result.size(); i++)
        //     cout << result[i] << " ";

        // cout << endl;
        if (verifySum(result))
            break;
        else
        {
            incrementPositions(positions, 1);
            result.clear();
        }
    }

    // cout << endl;

    return result;
}

int main()
{
    int C;
    cin >> C;
    string line;
    vector<string> lines;
    int total = 0;
    while (C--)
    {
        total = 0;
        cin >> line;

        for (int i = 0; i < line.size(); i++)
            if (line[i] == 'P')
                total++;
        vector<int> tpNumbers(total, 0);

        while (true)
        {
            cin >> line;
            if (line[0] == 'T' && line[1] == 'P')
            {
                cout << "TP ";
                int sum = 0;
                for (int i = 0; i < tpNumbers.size(); i++)
                {
                    cout << tpNumbers[i] << " ";
                    sum += tpNumbers[i];
                }
                cout << sum << endl;
                break;
            }

            int count = 0;
            for (int i = line.size() - 1; i >= 0; i--)
                if (line[i] >= '0' && line[i] <= '9')
                    count++;
            string name = line.substr(0, line.size() - count);
            cout << name << " ";
            string number = line.substr(line.size() - count, count);
            vector<int> result = numbers(number, total);
            for (int i = 0; i < result.size(); i++)
            {
                cout << result[i] << " ";
                tpNumbers[i] += result[i];
            }

            cout << endl;
        }
    }

    return 0;
}