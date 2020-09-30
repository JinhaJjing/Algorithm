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
				if (!visited[i]) { //�湮���� ���� ��尡 �ִٸ�
					root = i;
					exist = true;
					break;
				}
			}
		}

		cout << answer << "\n";
		//��� �� 0���� �ʱ�ȭ
		answer = 0;
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
	}

	return 0;
}