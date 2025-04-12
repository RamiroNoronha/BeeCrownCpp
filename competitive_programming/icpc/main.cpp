#include <string>
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

#define EP 20
#define INF 10000

bool enableLogs = false;
vector<vector<pair<int, int>>> values;
vector<tuple<int, int, int>> finalResult;
int T, P;
// T = numero de times
bool compareTuples(const tuple<int, int, int> &a, const tuple<int, int, int> &b)
{
    if (get<1>(a) != get<1>(b))
    {
        return get<1>(a) > get<1>(b); 
    }
    if (get<2>(a) != get<2>(b))
    {
        return get<2>(a) < get<2>(b); 
    }
    return get<0>(a) < get<0>(b); 
}

vector<tuple<int, int, int>> createFinalResult(int newEp)
{
    vector<tuple<int, int, int>> result(T);

    for (int i = 0; i < T; i++)
    {
        int dones = 0;
        int penality = 0;
        for (int j = 0; j < P; j++)
        {

            if (values[i][j].second > -1)
            {
                dones++;
                penality += (values[i][j].second + ((values[i][j].first - 1) * newEp));
            }
        }
        result[i] = make_tuple(i, dones, penality);
    }

    sort(result.begin(), result.end(), compareTuples);

    if (enableLogs)
    {
        cout << "Final Result: " << newEp << endl;
        for (int i = 0; i < T; i++)
        {
            cout << "Time " << get<0>(result[i]) + 1 << ": " << get<1>(result[i]) << " Penalidade: " << get<2>(result[i]) << endl;
        }
    }
    return result;
}

bool isValid(int newEp)
{
    vector<tuple<int, int, int>> result = createFinalResult(newEp);
    if (enableLogs)
    {
        cout << "Final Result Real: " << newEp << endl;
        for (int i = 0; i < T; i++)
        {
            cout << "Time " << get<0>(finalResult[i]) + 1 << ": " << get<1>(finalResult[i]) << " Penalidade: " << get<2>(finalResult[i]) << endl;
        }
    }

    for (int i = 0; i < T - 1; i++)
    {

        if (get<0>(result[i]) != get<0>(finalResult[i]))
        {
            if (enableLogs)
            {
                cout << "Deu ruim1" << endl;
            }
            return false;
        }
        else if (get<1>(finalResult[i]) == get<1>(finalResult[i + 1]) && get<2>(finalResult[i]) == get<2>(finalResult[i + 1]))
        {
            if (get<2>(result[i]) != get<2>(result[i + 1]))
            {
                if (enableLogs)
                {
                    cout << "Deu ruim2" << endl;
                }
                return false;
            }
        }
        else if (get<1>(result[i]) == get<1>(result[i + 1]) && get<2>(result[i]) >= get<2>(result[i + 1]))
        {
            if (enableLogs)
            {
                cout << "Deu ruim" << endl;
                cout << "Time " << get<0>(result[i]) + 1 << ": " << get<1>(result[i]) << " Penalidade: " << get<2>(result[i]) << endl;
                cout << "Time " << get<0>(result[i + 1]) + 1 << ": " << get<1>(result[i + 1]) << " Penalidade: " << get<2>(result[i + 1]) << endl;
            }
            return false;
        }
    }
    return true;
}

int minimumBinarySearch()
{
    int left = 1;
    int right = INF;
    int answer = 20;
    int mid = answer;
    while (left <= right)
    {

        if (isValid(mid))
        {

            answer = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
        mid = left + (right - left) / 2;
    }
    return answer;
}

int maximumBinarySearch(int left)
{
    int right = INF;
    int mid = 0;
    int answer = left;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (enableLogs)
        {
            cout << "left: " << left << " right: " << right << " mid: " << mid << endl;
        }

        if (isValid(mid))
        {

            answer = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return answer;
}

int main()
{
    // numero de times e problemas

    // calculo penalidade: TP + EP x FA
    // T = numero de times
    // P = numero de problemas
    // TP = Penalidade de tempo
    // EP = Penalidade de erro
    // FA = Numero de tentativas frustradas

    while (cin >> T >> P)
    {
        if (T == 0 && P == 0)
            break;

        values.clear();
        finalResult.clear();

        values = vector<vector<pair<int, int>>>(T, vector<pair<int, int>>(P));

        int tryies = 0;
        int time = 0;
        for (int i = 0; i < T; i++)
        {
            for (int j = 0; j < P; j++)
            {
                string result;
                cin >> result;
                string acc = "";
                for (int k = 0; k < result.length(); k++)
                {
                    if (result[k] == '/')
                    {
                        // numéro de tentativas para resolver o problema
                        if (enableLogs)
                        {
                            cout << "tryies: " << acc << endl;
                        }
                        tryies = stoi(acc);
                        values[i][j].first = tryies;

                        acc = "";
                        continue;
                    }

                    acc += result[k];
                }
                // -1 simboliza q o problema não foi resolvido, caso seja != -1
                // indica o tempo que demorou para resolver o problema
                if (enableLogs)
                {
                    cout << "time: " << acc << endl;
                }
                time = acc == "-" ? -1 : stoi(acc);
                values[i][j].second = time;
            }
        }

        finalResult = createFinalResult(EP);

        int firtMinimum = minimumBinarySearch();
        cout << firtMinimum << " ";
        int max = maximumBinarySearch(firtMinimum);
        cout << (max == INF ? "*" : to_string(max)) << endl;

        if (enableLogs)
        {
            cout << "----------------------------------------" << endl;
        }
    }

    return 0;
}