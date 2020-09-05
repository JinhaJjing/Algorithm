// https://www.acmicpc.net/problem/1010
// dp

#include <iostream>
#include <cstring>

using namespace std;

// 조합 mCn을 dp로

int dp[31][31];

int comb(int n, int m) {
	if (n == m || m == 0) return 1;
	if (dp[n][m]) return dp[n][m];
	return dp[n][m] = comb(n - 1, m - 1) + comb(n - 1, m);
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int N, M;
		cin >> N >> M;
		cout << comb(M, N) << endl;
	}
	return 0;
}