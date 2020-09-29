// https://www.acmicpc.net/problem/1260
// BFS

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <string.h>
#define MAX 1001

using namespace std;

int map[MAX][MAX];
int visited[MAX];
queue<int> q;
int N, M, answer=0;

void bfs(int root) {
	visited[root] = 1;
	q.push(root); // 1-1. 큐의 끝에 추가

	// 3. 큐가 소진될 때까지 계속한다.
	while (!q.empty()) {
		int r = q.front();
		q.pop(); // 큐의 앞에서 노드 추출

		// 2-2. 큐에서 꺼낸 노드와 인접한 노드들을 모두 차례로 방문한다.
		for (int i = 1; i <= N; i++) {
			if (map[r][i] == 1 && !visited[i]) {
				visited[i] = 1; // (방문한 노드 체크)
				q.push(i); // 2-3. 큐의 끝에 추가
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int m = 0; m < M; m++) {
		int u, v;
		cin >> u >> v;
		map[u][v] = 1;
		map[v][u] = 1;
	}

	bool exist = true;
	int root=1;

	while (exist) {
		bfs(root);

		answer++;
		exist = false;
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) {
				root = i;
				exist = true;
				break;
			}
		}
	}

	cout << answer;
	return 0;
}