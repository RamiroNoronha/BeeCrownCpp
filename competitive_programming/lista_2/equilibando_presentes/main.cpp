#include <iostream>
#include <vector>
#include <string>
#include <tuple>
using namespace std;
#define INF 0x3f3f3f3f
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define logs false

int N, T, A, B;
vector<int> P, memo;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;
        P = vector<int>(N);
        for (int i = 0; i < N; i++)
            cin >> P[i];
        memo = vector<int>(N + 1, 0);

        memo[0] = 0;
        A = 0;
        B = 0;
        A += P[0];
        memo[1] += A;
        if (memo[1] > 5)
        {
            cout << "Ho Ho Ho!" << endl;
            continue;
        }
        bool flag = false;
        for (int i = 2; i <= N; i++)
        {
            if (A + P[i - 1] - B > 5)
            {

                B += P[i - 1];
                memo[i] = abs(A - B);
            }
            else
            {
                A += P[i - 1];
                memo[i] = abs(A - B);
            }
            if (logs)
            {
                cout << "i: " << i << " A: " << A << " B: " << B << endl;
                cout << "memo[i]: " << memo[i] << endl;
            }
            if (memo[i] > 5)
            {
                flag = true;
                break;
            }
        }

        if (flag)
        {
            cout << "Ho Ho Ho!" << endl;
            continue;
        }
        else
        {
            cout << "Feliz Natal!" << endl;
        }
    }
}