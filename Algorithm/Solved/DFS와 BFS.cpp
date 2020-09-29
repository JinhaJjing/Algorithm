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
	// 1. root ��� �湮
	visited[root] = 1;
	// 2. root ���� ������ ������ ��� �湮
	for (int i = 1; i <= N; i++) {// 3. root ���� ������ ���� ������ ���� �������� DFS�� ����
		if (map[root][i] == 1 && !visited[i]) {
			dfs(i); // 4. �湮���� ���� ������ ã�´�.
		}
	}
}

void bfs(int root) {
	visited[root] = 1;
	q.push(root); // 1-1. ť�� ���� �߰�

	// 3. ť�� ������ ������ ����Ѵ�.
	while (!q.empty()) {
		int r = q.front();
		q.pop(); // ť�� �տ��� ��� ����
		cout << r << " ";

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