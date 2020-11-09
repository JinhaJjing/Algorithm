// https://www.acmicpc.net/problem/9466
// DFS

#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#define MAX 1001

using namespace std;

vector<int> map[MAX];
int visited[MAX];
int cycle[MAX];
int T, N, M, answer = 0;

void dfs(int root) {
	if (cycle[root]==1) return; //�̹� ����Ŭ�� ���ԵǾ��ִٸ�

	visited[root] = 1;
	int next = map[root][0];
	if (!visited[next]) { 
		dfs(next);
		answer++;
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
			map[v].push_back(n + 1);
		}

		for (int i = 1; i <= N; i++) {
			if (!visited[i]) { //�湮���� ���� ��尡 �ִٸ�
				dfs(i);
			}
		}

		cout << N - answer << "\n";
		//��� �� 0���� �ʱ�ȭ
		answer = 0;
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
	}

	return 0;
}