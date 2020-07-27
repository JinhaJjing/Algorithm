// https://programmers.co.kr/learn/courses/30/lessons/17679
// 대소문자, 구현

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<string> board) {
	int answer = 0;
	int dx[4] = { 0,1,1,0 };//시계방향
	int dy[4] = { 1,1,0,0 };
	int nx, ny, popCount=1;

	while (popCount > 0) {
		popCount = 0;

		//board한번 훑기
		for (int x = 0; x < m-1; x++) {
			for (int y = 0; y < n-1; y++) {
				bool pop = true;
				//4블록 확인
				for (int idx = 0; idx < 4; idx++) {
					char curFriend = board[x].at(y);
					nx = x + dx[idx];
					ny = y + dy[idx];
					char newFriend = board[nx].at(ny);

					//대소문자 구분 X, 프렌즈가 다르면
					if (tolower(curFriend) != tolower(newFriend) || curFriend == ' ' || newFriend == ' ') {
						pop = false;
						break;
					}
				}

				//모두 같은 프렌즈라면
				if (pop) {
					popCount++;
					//4개프렌즈 소문자화
					for (int index = 0; index < 4; index++) {
						int nnx = nx + dx[index];
						int nny = ny + dy[index];
						if ((board[nnx].at(nny) >= 'A') && (board[nnx].at(nny) <= 'Z')) //대문자프렌즈만 카운트에 더함
							board[nnx].at(nny) = tolower(board[nnx].at(nny)); //마지막에 nx와 ny는 원래 자리로 돌아오니까?
					}
				}
			}
		}

		//터뜨리기
		for (int cx = 0; cx < m; cx++) {
			for (int cy = 0; cy < n; cy++) {
				if ((board[cx].at(cy) >= 'a') && (board[cx].at(cy) <= 'z')) {
					board[cx].at(cy) = ' ';
					answer++;
				}
			}
		}

		//프렌즈 바닥으로 내리기
		//인덱스 생각해야해서 머리로 잘 안그려짐.. . 펜 필요
		//여기가 핵심!?
		for (int i = m - 1; i >= 0; i--) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == ' ') {
					for (int k = i - 1; k >= 0; k--) {
						if (board[k][j] != ' ') {
							board[i][j] = board[k][j];
							board[k][j] = ' ';
							break;
						}
					}
				}
			}
		}
	}

	return answer;
}
// 무식하게 짯나보다.. 4개블록을 확인하면 바로 소문자로 만들게끔 하면 중복코드가 줄음

int main(void)
{
	//12
	cout << "사라지는 블럭 수 : " << solution(6, 2, { "DD", "CC", "AA", "AA", "CC", "DD" }) << "\n" << endl;
	//8
	cout << "사라지는 블럭 수 : " << solution(8, 2, { "FF", "AA", "CC", "AA", "AA", "CC", "DD", "FF" }) << "\n" << endl;
	//24
	cout << "사라지는 블럭 수 : " << solution(5, 6, { "AAAAAA", "BBAATB", "BBAATB", "JJJTAA", "JJJTAA" }) << "\n" << endl;
	
	return 0;
}