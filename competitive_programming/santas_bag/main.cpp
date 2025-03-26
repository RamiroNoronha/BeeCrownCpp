#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

tuple<int, int, int> santasBagMax(int W, int n, vector<int> &weights, vector<int> &qts, vector<vector<tuple<int, int, int>>> &memoTable)
{
    if (W == 0 || n == 0)
        return {0, 0, 0};

    if (get<0>(memoTable[n][W]) != -1)
        return memoTable[n][W];

    int valueWithNewPresent = 0;
    int resultWithNewPresentQuantity = 0;
    int weightWithNewPresent = 0;

    if (weights[n - 1] <= W)
    {
        auto resultWithNewPresent = santasBagMax(W - weights[n - 1], n - 1, weights, qts, memoTable);
        valueWithNewPresent = qts[n - 1] + get<0>(resultWithNewPresent);
        resultWithNewPresentQuantity = get<1>(resultWithNewPresent);
        weightWithNewPresent = weights[n - 1] + get<2>(resultWithNewPresent);
    }
    auto resultWithoutNewPresent = santasBagMax(W, n - 1, weights, qts, memoTable);
    int valueWithoutNewPresent = get<0>(resultWithoutNewPresent);

    if (valueWithNewPresent > valueWithoutNewPresent)
        return memoTable[n][W] = {valueWithNewPresent, resultWithNewPresentQuantity + 1, weightWithNewPresent};
    else
        return memoTable[n][W] = {valueWithoutNewPresent, get<1>(resultWithoutNewPresent), get<2>(resultWithoutNewPresent)};
}

int main()
{
    int N;
    int W = 50;
    cin >> N;

    while (N--)
    {
        int Pac;
        cin >> Pac;
        vector<vector<tuple<int, int, int>>> memoTable(Pac + 1, vector<tuple<int, int, int>>(W + 1, {-1, 0, 0}));
        vector<int> weights;
        vector<int> qts;

        while (Pac--)
        {
            int qt, weight;
            cin >> qt >> weight;
            weights.push_back(weight);
            qts.push_back(qt);
        }
        auto result = santasBagMax(W, weights.size(), weights, qts, memoTable);
        cout << get<0>(result) << " brinquedos" << endl;
        cout << "Peso: " << get<2>(result) << " kg" << endl;
        cout << "sobra(m) " << weights.size() - get<1>(result) << " pacote(s)" << endl;
        cout << endl;
    }

    return 0;
}