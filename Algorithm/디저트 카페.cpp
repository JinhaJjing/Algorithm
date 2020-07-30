// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5VwAr6APYDFAWu
// dfs, direction

#include<iostream>
#include<algorithm>
using namespace std;

int T, N;
int map[20][20];
bool visited[100];
int dx[4] = { 1,-1,-1,1 }; // аб ©Л аб ©Л
int dy[4] = { 1,1,-1,-1 }; // ╩С го го ╩С

int answer;
int sx, sy;

void dfs(int x, int y, int dir, int count) {

	if (x == sx && y == sy)
		answer = max(answer, count);

	for (int i = 0; i < 2; i++) {

		int nx, ny;
		if (i == 0) {
			nx = x + dx[dir];
			ny = y + dy[dir];
		}
		else {
			if (x == sx && y == sy) continue;

			if (dir < 3) {
				nx = x + dx[dir + 1];
				ny = y + dy[dir + 1];

			}
		}

		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

		if (nx == sx && ny == sy) {
			dfs(nx, ny, dir, count + 1);
			break;
		}

		if (!visited[map[nx][ny]]) {
			visited[map[nx][ny]] = true;
			dfs(nx, ny, dir, count + 1);
			visited[map[nx][ny]] = false;
		}
	}
	return;
}

int main() {
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;

		answer = 0;
		memset(map, 0, sizeof(map));
		memset(visited, false, sizeof(visited));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				cin >> map[i][j];
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				sx = i;
				sy = j;
				visited[map[i][j]] = true;
				dfs(i, j, 0, 0);
				visited[map[i][j]] = false;
			}
		}

		cout << "#" << t + 1 << ' ' << answer << '\n';
	}

	return 0;
}