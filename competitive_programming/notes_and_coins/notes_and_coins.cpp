#include <stdio.h>

int main()
{
    int n[] = {100, 50, 20, 10, 5, 2};
    int n_usage[] = {0, 0, 0, 0, 0, 0};
    int n_size = 6;
    int n_index = 0;

    double m[] = {1, 0.50, 0.25, 0.10, 0.05, 0.01};
    int m_usage[] = {0, 0, 0, 0, 0, 0};
    int m_size = 6;
    int m_index = 0;

    double value;
    double epsilon = 0.001;

    scanf("%lf", &value);

    printf("NOTAS:\n");
    while (n_index < n_size)
    {
        if (value >= n[n_index])
        {
            value -= n[n_index];
            n_usage[n_index]++;
            continue;
        }
        printf("%d nota (s) de R$ %d.00\n", n_usage[n_index], n[n_index]);
        n_index++;
    }
    printf("MOEDAS:\n");
    while (m_index < m_size)
    {

        if (value >= m[m_index] - epsilon)
        {
            value -= m[m_index];
            m_usage[m_index]++;
            continue;
        }

        printf("%d moeda (s) de R$ %.2f\n", m_usage[m_index], m[m_index]);
        m_index++;
    }

    return 0;
}