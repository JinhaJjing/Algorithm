// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PoOKKAPIDFAUq&categoryId=AV5PoOKKAPIDFAUq&categoryType=CODE
// dfs, direction

#include<iostream>
#include<algorithm>
using namespace std;

int map[8][8];
bool visited[8][8] = { false };
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int N, K, ans;
bool reduce = false;

void dfs(int x, int y, int cnt, int prvHeight) {

	visited[x][y] = true;
	if (cnt > ans)	ans = cnt;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny] == true) continue;
		else {
			if (!reduce) { // 안깎은 상태
				if (map[nx][ny] >= map[x][y]) { // 같은 위치거나 높은 위치
					if (map[nx][ny] - K < map[x][y]) {
						reduce = true;
						dfs(nx, ny, cnt + 1, map[x][y] - 1);
					}
				}
				else // 낮은 위치
					dfs(nx, ny, cnt + 1, map[nx][ny]);
			}
			else { // 깎은 상태
				if (map[nx][ny] < prvHeight)
					dfs(nx, ny, cnt + 1, map[nx][ny]);
			}
		}
	}

	visited[x][y] = false;
	return;
}

int main() {
	int TC;
	cin >> TC;

	for (int t = 0; t < TC; t++) {
		ans = 0;
		cin >> N >> K;

		int highest = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				highest = max(highest, map[i][j]);
			}
		}

		// highest일 경우에 dfs실행
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == highest)
					dfs(i, j, 1, map[i][j]);
			}
		}

		cout << "#" << t + 1 << ' ' << ans << '\n';
	}

	return  0;
}