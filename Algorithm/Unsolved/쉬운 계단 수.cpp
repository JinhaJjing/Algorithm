//https://www.acmicpc.net/problem/10844
//DP

//기본 테케는 통과하는데 왜 틀린지 모르게씅ㅁ...

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100 + 1

long long dp[MAX][11] = { 0, };

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) dp[i][j] = dp[i - 1][j + 1];
			else if (j == 9) dp[i][j] = dp[i - 1][j - 1];
			else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
		}
	}

	long long sum = 0;
	for (long long a : dp[N]) {
		sum += a;
	}
	cout << sum % 1000000000 << "\n";
}