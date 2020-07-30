// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5V1SYKAaUDFAWu
// dfs

#include<iostream>
#include<algorithm>

using namespace std;

int film[13][20];
int temp[13][20];
int T, D, W, K;
int answer;

bool check() {
	int same;
	for (int i = 0; i < W; i++) {
		same = 1;
		for (int j = 0; j < D - 1; j++) {
			if (same >= K) break;
			if (temp[i][j] == temp[i + 1][j])
				same++;
			else same = 1;
		}
		if (same < K) return false;
	}
	return true;
}

void dfs(int cnt) {
	if (cnt >= answer) return;
	if (check()) answer = min(answer, cnt);

	return;
}

int main() {
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> D >> W >> K;
		for (int i = 0; i < W; i++) {
			for (int j = 0; j < D; j++) {
				cin >> film[i][j];
			}
		}

		dfs();
		memset(film, 0, sizeof(film));

		cout << "#" << t + 1 << ' ' << answer << '\n';
	}

	return 0;
}