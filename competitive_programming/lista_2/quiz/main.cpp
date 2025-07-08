#include <bits/stdc++.h>
using namespace std;

vector<int> P;
vector<double> prob; // prob[i] será armazenada como fração: Ci/100
int N, K;
vector<vector<double>> memo;

double solve(int i, int k)
{
    if (i == N)
        return 0;
    if (memo[i][k] != -1)
        return memo[i][k];

    // Se responder a pergunta i:
    // Chance de acerto * (prêmio garantido + valor esperado do restante)
    double ans = prob[i] * (P[i] + solve(i + 1, k));

    // Se pular a pergunta i (usando um pulo)
    if (k > 0)
        ans = max(ans, (double)P[i] + solve(i + 1, k - 1));

    return memo[i][k] = ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> N >> K)
    {
        P.resize(N);
        prob.resize(N);

        // Leitura dos prêmios
        for (int i = 0; i < N; ++i)
            cin >> P[i];

        // Leitura das chances (em %) e converte para fração
        for (int i = 0; i < N; ++i)
        {
            cin >> prob[i];
            prob[i] /= 100.0;
        }

        memo.assign(N, vector<double>(K + 1, -1));

        cout << fixed << setprecision(2) << solve(0, K) << "\n";
    }

    return 0;
}