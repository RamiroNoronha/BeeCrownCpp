#include <iostream>
#include <vector>

using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

void printBooleanArray(int num, int size)
{
    for (int i = 0; i < size; i++)
    {
        bool bit = num & (1 << i);
        cout << bit << " ";
    }
    cout << endl;
}

void printState(vector<bool> &state)
{
    for (int i = 0; i < state.size(); i++)
    {
        cout << state[i] << " ";
    }
    cout << endl;
}

void initializeSwitches(vector<vector<bool>> &switches, int N)
{
    for (int i = 0; i < N; i++)
    {
        int k;
        cin >> k;
        int lamp = 0;
        for (int j = 0; j < k; j++)
        {
            int action;
            cin >> action;
            action--;
            switches[i][action] = true;
        }
    }
}

void clickSwitch(vector<bool> &state, vector<bool> &switches, int M)
{
    for (int i = 0; i < M; i++)
    {
        state[i] = state[i] ^ switches[i];
    }
}

bool isAllLampsOff(vector<bool> &state)
{
    for (int i = 0; i < state.size(); i++)
    {
        if (state[i] == 1)
        {
            return false;
        }
    }
    return true;
}

bool statesAreEquals(vector<bool> &state1, vector<bool> &state2)
{
    for (int i = 0; i < state1.size(); i++)
    {
        if (state1[i] != state2[i])
        {
            return false;
        }
    }
    return true;
}

int analizeSwitchesActions(vector<vector<bool>> &switches, int N, vector<bool> &state, vector<bool> &initialState, int M)
{
    int count = 0;
    bool canFail = false;

    while (true)
    {

        for (int i = 0; i < N; i++)
        {
            clickSwitch(state, switches[i], M);
            count++;
            if (isAllLampsOff(state))
            {
                return count;
            }
        }
        if (statesAreEquals(state, initialState))
        {
            if (canFail)
            {
                return -1;
            }
            canFail = true;
        }
    }
}

int main()
{
    int N, M, L;
    cin >> N >> M;
    cin >> L;

    vector<bool> state(M, 0);
    vector<bool> initialState(M, 0);
    for (int i = 0; i < L; i++)
    {
        int lamp;
        cin >> lamp;
        lamp--;
        state[lamp] = true;
        initialState[lamp] = true;
    }

    vector<vector<bool>> switches(N, vector<bool>(M, false));
    initializeSwitches(switches, N);

    int result = analizeSwitchesActions(switches, N, state, initialState, M);
    cout << result << endl;

    return 0;
}