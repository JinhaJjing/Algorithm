#include <vector>
#include <queue>

using namespace std;

int dx[4] = { -1,1,0,0 }; // �����¿�
int dy[4] = { 0,0,-1,1 };
int visited[100][100] = {0, };
queue<pair<int,int>> q;

int bfs(int m, int n, vector<vector<int>> picture) {
	int area = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		int std_color = picture[x][y];
		visited[x][y] = true;
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (!(nx>=m || ny>=n || nx<0 || ny<0)) {
				int cur_color = picture[nx][ny];
				if (!visited[nx][ny] && std_color == cur_color) { // �湮���� ���� ���̰� ������ ���� = Ȯ��
					q.push(make_pair(nx, ny));
					visited[nx][ny] = true;
					area++;
				}
			}
		}
	}

	return area;
}

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	memset(visited, 0, sizeof(visited));

	vector<int> answer(2);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && (picture[i][j]!=0)) {
				number_of_area++;
				q.push(make_pair(i, j));
				int cur_area_size = bfs(m, n, picture);
				max_size_of_one_area = max_size_of_one_area < cur_area_size ? cur_area_size : max_size_of_one_area;
			}
		}
	}
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;

	return answer;
}

int main() {
	int m,n;
	vector<vector<int>> picture;
	m = 6;
	n = 4;
	picture = { {1, 1, 1, 0},{1, 2, 2, 0},{1, 0, 0, 1},{0, 0, 0, 1},{0, 0, 0, 3},{0, 0, 0, 3} };
	//picture = { {1, 1, 1, 0},{1, 1, 1, 0},{0, 0, 0, 1},{0, 0, 0, 1},{0, 0, 0, 1},{0, 0, 0, 1} };

	solution(m,n,picture);
}