// https://www.acmicpc.net/problem/10451
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
int T, N, M, answer = 0;

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
				break;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		for (int n = 0; n < N; n++) {
			int v;
			cin >> v;
			map[n + 1][v] = 1;
		}

		bool exist = true;
		int root = 1;

		while (exist) {
			bfs(root);

			answer++;
			exist = false;
			for (int i = 1; i <= N; i++) {
				if (!visited[i]) { //방문하지 않은 노드가 있다면
					root = i;
					exist = true;
					break;
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