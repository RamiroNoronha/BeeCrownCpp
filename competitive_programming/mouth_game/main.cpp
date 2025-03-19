#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

int main()
{
    string N;

    cin >> N;

    int result = 0;

    //Property
    //(A * B) mod C = (A mod C * B mod C) mod C
    // 10 ^ i mod 3 == 1 for every i

    for (int i = 0; i < N.size(); i++)
    {
        int digit = N[i] - '0';

        result += digit % 3;
    }

    result %= 3;

    cout << result << endl;
    return 0;
}