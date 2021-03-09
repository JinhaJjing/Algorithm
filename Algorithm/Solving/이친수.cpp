//https://www.acmicpc.net/problem/2193
//DP

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long d[91][2] = { {0, 0}, {0, 0}, {1, 0} };

    if (n <= 2)
        cout << 1 << "\n";

    else
    {
        for (int i = 3; i <= n; i++)
        {
            d[i][0] = d[i - 1][0] + d[i - 1][1];
            d[i][1] = d[i - 1][0];
        }

        cout << d[n][0] + d[n][1] << "\n";
    }
}