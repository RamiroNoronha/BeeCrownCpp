#include <iostream>
#include <vector>
#include <set>
#include <functional>
using namespace std;

vector<vector<int>> board;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

void printTable(int N, int M)
{
    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = 0; j < M; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isValidPosition(pair<int, int> &p, int N, int M)
{

    return (p.first >= 0 && p.first < N && p.second >= 0 && p.second < M);
}

pair<int, int> movedownLeft(pair<int, int> &p)
{
    return make_pair(p.first - 1, p.second - 1);
}

pair<int, int> movedownRight(pair<int, int> &p)
{
    return make_pair(p.first + 1, p.second - 1);
}

pair<int, int> moveupLeft(pair<int, int> &p)
{
    return make_pair(p.first - 1, p.second + 1);
}

pair<int, int> moveupRight(pair<int, int> &p)
{
    return make_pair(p.first + 1, p.second + 1);
}

pair<int, int> nextMove(int i, pair<int, int> &p)
{
    if (i == 0)
        return movedownLeft(p);
    else if (i == 1)
        return movedownRight(p);
    else if (i == 2)
        return moveupLeft(p);
    else
        return moveupRight(p);
}

int backTrackinR(pair<int, int> position, int N, int M)
{
    if (!isValidPosition(position, N, M))
        return 0;
    int temp = board[position.first][position.second];
    board[position.first][position.second] = 1;
    // cout << "Saida" << endl;
    // printTable(board, N, M);
    // cout << endl;
    vector<pair<int, int>> checkers(4);
    checkers[0] = (movedownLeft(position));
    checkers[1] = (movedownRight(position));
    checkers[2] = (moveupLeft(position));
    checkers[3] = (moveupRight(position));
    int maxValue = 0;
    for (int i = 0; i < checkers.size(); i++)
    {

        pair<int, int> neibor = checkers[i];

        if (!isValidPosition(neibor, N, M) || board[neibor.first][neibor.second] != 2)
            continue;

        pair<int, int> next = nextMove(i, neibor);

        if (!isValidPosition(next, N, M) || board[next.first][next.second] != 0)
            continue;

        int pairAcc = 1;
        board[neibor.first][neibor.second] = 0;
        board[position.first][position.second] = 0;
        pairAcc += backTrackinR(next, N, M);
        board[neibor.first][neibor.second] = 2;
        board[position.first][position.second] = 1;
        if (pairAcc > maxValue)
            maxValue = pairAcc;
    }

    board[position.first][position.second] = temp;

    // cout << "Valores: ";
    // for (auto i : values)
    //     cout << i << " ";
    // cout << endl;

    return maxValue;
}

int getMaxCheckers(vector<pair<int, int>> &ourCheckers, int N, int M)
{
    int maxValue = 0;
    for (auto pair : ourCheckers)
    {
        int value = backTrackinR(pair, N, M);
        if (value > maxValue)
            maxValue = value;
    }

    // cout << "Valores por peca: ";
    // for (auto i : values)
    //     cout << i << " ";
    // cout << endl;
    return maxValue;
}

int main()
{
    int N, M;
    cin >> N >> M;

    while (N != 0 && M != 0)
    {
        board = vector<vector<int>>(N, vector<int>(M, 0));
        // vector<vector<int>> newBoard(N, vector<int>(M, 0));
        vector<pair<int, int>> ourCheckers;
        int quantity = (N * M) / 2;
        for (int i = 0, j = 0, r = quantity; r >= 0; r--, j += 2)
        {
            if (j >= M)
            {
                i++;
                j = (i % 2 == 0) ? 0 : 1;
            }
            if (i >= N)
                break;
            int x;
            cin >> x;
            // cout << i << " " << j << ": " << x << " " << endl;
            if (x == 1)
            {
                ourCheckers.push_back(make_pair(i, j));
            }
            board[i][j] = x;
        }

        // cout << endl;
        // cout << "Case " << N << "x" << M << ": " << endl;
        // printTable(board, N, M);
        // getMaxCheckers(board, ourCheckers, N, M);
        cout << getMaxCheckers(ourCheckers, N, M) << endl;

        // cout << endl;
        cin >> N >> M;
    }

    return 0;
}