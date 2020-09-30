// https://www.acmicpc.net/problem/1707
// BFS

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <string.h>
#define MAX 20001

using namespace std;

vector<int> map[MAX];
int visited[MAX];
queue<int> q;
int V, E;

void bfs(int root) {
	visited[root] = 1;
	q.push(root); // 1-1. 큐의 끝에 추가

	// 3. 큐가 소진될 때까지 계속한다.
	while (!q.empty()) {
		int r = q.front();
		q.pop(); // 큐의 앞에서 노드 추출

		// 2-2. 큐에서 꺼낸 노드와 인접한 노드들을 모두 차례로 방문한다.

		for (int i = 0; i < map[r].size(); i++) {
			int next = map[r][i];
			if (visited[next] == 0) {
				if (visited[r] == 1) visited[next] = 2;  // (방문한 노드 체크)
				else if (visited[r] == 2) visited[next] = 1;
				q.push(next); // 2-3. 큐의 끝에 추가
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int K;
	cin >> K;
	for (int k = 0; k < K; k++) {
		cin >> V >> E;
		for (int e = 0; e < E; e++) {
			int u, v;
			cin >> u >> v;
			map[u].push_back(v);
			map[v].push_back(u);
		}

		for (int i = 1; i <= V; i++) {
			if (visited[i]==0) bfs(i); // 해당 노드를 아직 방문하지 않았다면
		}

		string answer = "YES";
		for (int i = 1; i <= V; i++) {
			for (int j = 0; j < map[i].size(); j++) {
				int next = map[i][j];
				if (visited[i] == visited[next]) answer = "NO";
			}
		}
		cout << answer << "\n";

		memset(map, 0, sizeof(map)); //모든 값 0으로 초기화
		memset(visited, 0, sizeof(visited));
	}

	return 0;
}