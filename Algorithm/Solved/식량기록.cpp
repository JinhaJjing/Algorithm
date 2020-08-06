// dp

#include <iostream>
using namespace std;

long long dp[31][31];

long long init(int K, int H)
{
	if (K < 0 || H < 0) return 0;
	if (K == 0) return 1;

	long long val = dp[K][H];
	if (val != 0) return val;
	return dp[K][H] = init(K, H - 1) + init(K - 1, H + 2);
}

int main()
{
	init(20, 0);

	int num;
	cin >> num;

	cout << dp[num][0] << endl;
}