// https://programmers.co.kr/learn/courses/30/lessons/67259
// 

#include <string>
#include <vector>

using namespace std;

int answer = 12500;
int dx[4] = { -1,1,0,0 };//상 하 좌 우
int dy[4] = { 0,0,-1,1 };
vector<vector<bool>> visited(25);
string direction = "vertical";

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

int solution(vector<vector<int>> board) {
	dfs(0, 0, board, direction);
	return answer;
}