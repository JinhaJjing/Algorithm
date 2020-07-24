// https://programmers.co.kr/learn/courses/30/lessons/64061
// stack

#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	stack<int> basket;

	for (int i : moves) {
		for (int j = 0; j < board.size(); j++) {
			if (board[j][i - 1] != 0) { // 인형이 존재
				basket.push(board[j][i-1]);
				board[j][i - 1] = 0;
				if (basket.size() >= 2) { // 바구니에 2개 이상이면 확인
					int top = basket.top();
					basket.pop();

					if (top == basket.top()) { // 2개가 연속
						basket.pop();
						answer += 2;
					}
					else
						basket.push(top);
				}
				break;
			}
		}
	}

	return answer;
}

int main() {
	vector<vector<int>> board;
	board = { {0, 0, 0, 0, 0},{0, 0, 1, 0, 3},{0, 2, 5, 0, 1},{4, 2, 4, 4, 2},{3, 5, 1, 3, 1} };
	vector<int> moves;
	moves = { 1, 5, 3, 5, 1, 2, 1, 4 };
	solution(board, moves);
}