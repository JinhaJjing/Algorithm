//https://www.acmicpc.net/problem/1003
//DP

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int T, N, dp[41] = { 1,0 };

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 2;i <= 41;i++)
		dp[i] = dp[i - 1] + dp[i - 2];

	cin >> T;
	while (T--) {
		cin >> N;
		cout << dp[N] << " " << dp[N + 1] << endl;
	}
}