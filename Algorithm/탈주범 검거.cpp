// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PpLlKAQ4DFAUq&categoryId=AV5PpLlKAQ4DFAUq&categoryType=CODE
// bfs, direction

#include<iostream>
#include<queue>
#include<string.h>

using namespace std;

int type[8][4] = { // �� �� �� ��
	{ 0, 0, 0, 0 },
	{ 1, 1, 1, 1 },
	{ 1, 0, 1, 0 },
	{ 0, 1, 0, 1 },
	{ 1, 1, 0, 0 },
	{ 0, 1, 1, 0 },
	{ 0, 0, 1, 1 },
	{ 1, 0, 0, 1 },
};

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int T, N, M, R, C, L;
int answer;
int tunnel[51][51];
bool visited[51][51] = { false, };

void bfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {R,C }, 1 });
	visited[R][C] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int depth = q.front().second;
		q.pop();

		if (depth == L) continue;

		for (int i = 0; i < 4; i++) {
			if (type[tunnel[x][y]][i]) { // ������ ������ �̵� �õ�
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx<0 || nx>N || ny<0 || ny>M) // �����
					continue;

				if (!visited[nx][ny]) { //����Ǿ��ְ� �湮 ��������
					if ((i == 0 && type[tunnel[nx][ny]][2]) // ��
						|| (i == 1 && type[tunnel[nx][ny]][3]) // ��
						|| (i == 2 && type[tunnel[nx][ny]][0]) // ��
						|| (i == 3 && type[tunnel[nx][ny]][1])) { // ��
						visited[nx][ny] = true;
						q.push({ { nx,ny },depth + 1 });
						answer++;
					}
				}
			}
		}
	}
	return;
}


int main() {
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> N >> M >> R >> C >> L;

		memset(visited, false, sizeof(visited));
		memset(tunnel, 0, sizeof(tunnel));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> tunnel[i][j];
			}
		}

		answer = 1;
		bfs();

		cout << "#" << t + 1 << ' ' << answer << '\n';
	}

	return 0;
}