#include <iostream>
#include <vector>
using namespace std;

// Função recursiva para gerar todas as combinações
void generateCombinations(vector<int> &combination, int index, int n)
{
    if (index == n)
    {
        cout << 3 << endl; // Imprime o número 3
        // Imprime a combinação atual
        for (int num : combination)
        {
            cout << num << " ";
        }
        cout << endl;
        return;
    }

    // Tenta adicionar 1
    combination[index] = 1;
    generateCombinations(combination, index + 1, n);

    // Tenta adicionar 2
    combination[index] = 2;
    generateCombinations(combination, index + 1, n);
}

int main()
{

    int n = 6; // Número de posições
    vector<int> combination(n);

    // Gera todas as combinações de 1 e 2
    generateCombinations(combination, 0, n);

    return 0;
}