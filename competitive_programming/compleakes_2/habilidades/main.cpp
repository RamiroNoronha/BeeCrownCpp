#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define logs false
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> custoSubirHabilidade(n);
    vector<int> recompensaPorConquista(m);
    vector<int> habilidade(n, 1);
    vector<int> custoTotalAcumulado(m, 0);
    vector<int> recompensaAcumulado(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> custoSubirHabilidade[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> recompensaPorConquista[i];
    }

    vector<vector<int>> L(m, vector<int>(n));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> L[i][j];
        }
    }

    long int maxValue = -INF;

    for (int i = 0; i < m; i++)
    {
        long int soma = 0;

        for (int j = 0; j < n; j++)
        {
            if (habilidade[j] < L[i][j])
            {
                soma += (L[i][j] - habilidade[j]) * custoSubirHabilidade[i];
                habilidade[j] = L[i][j];
            }
        }
        custoTotalAcumulado[i] = i > 0 ? custoTotalAcumulado[i - 1] + soma : soma;
        recompensaAcumulado[i] = i > 0 ? recompensaAcumulado[i - 1] + recompensaPorConquista[i] : recompensaPorConquista[i];

        if (maxValue < recompensaAcumulado[i] - custoTotalAcumulado[i])
        {
            maxValue = recompensaAcumulado[i] - custoTotalAcumulado[i];
        }
    }

    cout << maxValue << endl;
    return 0;
}