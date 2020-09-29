// https://www.acmicpc.net/problem/1260
// DFS, BFS

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
int N, M, V;

void dfs(int root) {
	cout << root << " ";
	// 1. root 노드 방문
	visited[root] = 1;
	// 2. root 노드와 인접한 정점을 모두 방문
	for (int i = 1; i <= N; i++) {// 3. root 노드와 인접한 정점 정점을 시작 정점으로 DFS를 시작
		if (map[root][i] == 1 && !visited[i]) {
			dfs(i); // 4. 방문하지 않은 정점을 찾는다.
		}
	}
}

void bfs(int root) {
	visited[root] = 1;
	q.push(root); // 1-1. 큐의 끝에 추가

	// 3. 큐가 소진될 때까지 계속한다.
	while (!q.empty()) {
		int r = q.front();
		q.pop(); // 큐의 앞에서 노드 추출
		cout << r << " ";

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

	cin >> N >> M >> V;
	for (int m = 0; m < M; m++) {
		int n1, n2;
		cin >> n1 >> n2;
		map[n1][n2] = 1;
		map[n2][n1] = 1;
	}

	dfs(V);

	memset(visited, 0, sizeof(visited));
	cout << "\n";

	bfs(V);

	return 0;
}