// https://www.acmicpc.net/problem/1012
// DFS

#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

int dx[4] = { -1,1,0,0 }; //상,하,좌,우
int dy[4] = { 0, 0,-1,1 };
int map[50][50] = { 0 };
int visited[50][50] = { 0 };
int answer = 0;
int T, M, N, K;


void dfs(int x,int y) {

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= N || ny >= M || nx < 0 || ny < 0) continue;

		if (visited[nx][ny] == 0 && map[nx][ny] == 1) {
			visited[nx][ny] = 1;
			dfs(nx, ny);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> M >> N >> K;

		for (int i = 0; i < K; i++) {
			int x,y;
			cin >> y >> x;
			map[x][y] = 1;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 1 && !visited[i][j]) { //방문하지 않은 노드의 값이 1이면
					answer++;
					visited[i][j] = 1;
					dfs(i, j);
				}
			}
		}

		cout << answer << "\n";
		//모든 값 0으로 초기화
		answer = 0;
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
	}

	return 0;
}