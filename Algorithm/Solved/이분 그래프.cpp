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
	q.push(root); // 1-1. ť�� ���� �߰�

	// 3. ť�� ������ ������ ����Ѵ�.
	while (!q.empty()) {
		int r = q.front();
		q.pop(); // ť�� �տ��� ��� ����

		// 2-2. ť���� ���� ���� ������ ������ ��� ���ʷ� �湮�Ѵ�.

		for (int i = 0; i < map[r].size(); i++) {
			int next = map[r][i];
			if (visited[next] == 0) {
				if (visited[r] == 1) visited[next] = 2;  // (�湮�� ��� üũ)
				else if (visited[r] == 2) visited[next] = 1;
				q.push(next); // 2-3. ť�� ���� �߰�
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
			if (visited[i]==0) bfs(i); // �ش� ��带 ���� �湮���� �ʾҴٸ�
		}

		string answer = "YES";
		for (int i = 1; i <= V; i++) {
			for (int j = 0; j < map[i].size(); j++) {
				int next = map[i][j];
				if (visited[i] == visited[next]) answer = "NO";
			}
		}
		cout << answer << "\n";

		memset(map, 0, sizeof(map)); //��� �� 0���� �ʱ�ȭ
		memset(visited, 0, sizeof(visited));
	}

	return 0;
}