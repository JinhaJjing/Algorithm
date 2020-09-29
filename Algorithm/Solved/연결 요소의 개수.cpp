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
	q.push(root); // 1-1. ť�� ���� �߰�

	// 3. ť�� ������ ������ ����Ѵ�.
	while (!q.empty()) {
		int r = q.front();
		q.pop(); // ť�� �տ��� ��� ����

		// 2-2. ť���� ���� ���� ������ ������ ��� ���ʷ� �湮�Ѵ�.
		for (int i = 1; i <= N; i++) {
			if (map[r][i] == 1 && !visited[i]) {
				visited[i] = 1; // (�湮�� ��� üũ)
				q.push(i); // 2-3. ť�� ���� �߰�
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