#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

#define IMPOSSIBLE 2147483647

int qtdCalculator(int width, int height, int L, int K, vector<int> &boards)
{
    // cout << "width: " << width << endl;
    // cout << "height: " << height << endl;
    // cout << "L: " << L << endl;
    // cout << "K: " << K << endl;
    // cout << "boards: ";
    // for (int i = 0; i < K; i++)
    // {
    //     cout << boards[i] << " ";
    // }
    // cout << endl;
    if (height % L != 0)
        return IMPOSSIBLE;

    int qtd = height / L;
    int count = 0;

    // cout << "qtd: " << qtd << endl;
    for (int i = K - 1; i >= 0 && qtd > 0; i--)
    {
        if (boards[i] > width)
            continue;
        if (boards[i] < width)
            break;
        // cout << "board completo: " << boards[i] << endl;
        count++;
        qtd--;
    }

    for (int i = 0, j = K - 1 - count; i < j && qtd > 0;)
    {
        if (boards[i] > width)
            break;
        if (boards[i] + boards[j] == width)
        {
            count += 2;
            // cout << "boards juntos: " << boards[i] << " + " << boards[j] << " = " << width << endl;
            i++;
            j--;
            qtd--;
        }
        else if (boards[i] + boards[j] < width)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    // cout << "count: " << count << endl;
    if (qtd != 0)
        return IMPOSSIBLE;

    return count;
}

int main()
{

    int N, M, L, K;
    const int m_cm = 100;
    while (true)
    {
        cin >> N >> M;
        if (N == 0 && M == 0)
            break;

        N *= m_cm;
        M *= m_cm;
        cin >> L;
        cin >> K;

        vector<int> boards(K, 0);
        for (int i = 0; i < K; i++)
        {
            cin >> boards[i];
            boards[i] *= m_cm;
        }
        sort(boards.begin(), boards.end());
        // cout << "First Try" << endl;
        int tryOne = qtdCalculator(N, M, L, K, boards);
        // cout << "tryOne: " << tryOne << endl;

        // cout << "Second Try" << endl;
        int tryTwo = qtdCalculator(M, N, L, K, boards);
        // cout << "tryTwo: " << tryTwo << endl;

        int result = min(tryOne, tryTwo);

        if (result == IMPOSSIBLE)
        {
            cout << "impossivel" << endl;
        }
        else
        {
            cout << result << endl;
        }
    }

    return 0;
}