// https://programmers.co.kr/learn/courses/30/lessons/67259
// bfs

#include <string>
#include <vector>
#include <queue>

using namespace std;

/*
void dfs(int x, int y, vector<vector<int>> board, string direction) {
	for (int b = 0; b < board.size(); b++) {
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (!visited[nx][ny] && !board[nx][ny]) {
				if (i == 0 || i == 1) {
					if (direction == "horizontal") a;//커브 카운트 늘리기
					direction = "vertical";
				}
				else {
					if (direction == "vertical") a;//커브 카운트 늘리기
					direction = "horizontal";
				}
				dfs(nx, ny, board, direction);
			}
		}
	}
	//cost = (visited-curve) X 100 + curve X 500 (it does not mean put here)
	answer = answer > cost ? cost : answer;
}
*/

//dfs(0, 0, board, direction);
//bfs로 돌림
//TODO: (@.@) 경로마다 cost를 어떻게 구하지..? 이해가안간다

int solution(vector<vector<int>> board) {
	int answer = 25*25*500;
	int dx[4] = { -1,1,0,0 };//상 하 좌 우
	int dy[4] = { 0,0,-1,1 };
	int N = board.size();
	vector<vector<int>> visited(N, vector<int>(N, 0));
	string direction = "";
	queue<pair<int, int>> q;
	visited[0][0] = 1;
	q.push(make_pair(0, 0));
	int cost = 0;

	while (!q.empty()) {
		pair<int, int> node = q.front();
		q.pop();

		if (node.first == N - 1 && node.second == N - 1)
			answer = answer > cost ? cost : answer;

		for (int i = 0; i < 4; i++) {
			int nx = node.first + dx[i];
			int ny = node.second + dy[i];

			if (!(nx >= 0 && ny >= 0 && nx < N && ny < N)) continue;

			if (!visited[nx][ny] && !board[nx][ny]) {
				if (i == 0 || i == 1) {
					if (node.first+node.second == 0) direction = "vertical";
					if (direction == "horizontal") {
						direction = "vertical";
						cost += 500;
					}
					else cost += 100;
				}
				else {
					if (node.first + node.second == 0) direction = "horizontal";
					if (direction == "vertical") {
						direction = "horizontal";
						cost += 500;
					}
					else cost += 100;
				}
				visited[nx][ny] = true;
				q.push(make_pair(nx, ny));
			}
		}
	}

	return answer;
}

int main() {
	solution({ {0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,0},{0,0,0,0,0,1,0,0},{0,0,0,0,1,0,0,0},
		{0,0,0,1,0,0,0,1},{0,0,1,0,0,0,1,0},{0,1,0,0,0,1,0,0},{1,0,0,0,0,0,0,0} });
	solution({ {0,0,0},{0,0,0},{0,0,0} });
}