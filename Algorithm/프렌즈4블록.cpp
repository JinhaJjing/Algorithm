// https://programmers.co.kr/learn/courses/30/lessons/17679
// ��ҹ���, ����

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<string> board) {
	int answer = 0;
	int dx[4] = { 0,1,1,0 };//�ð����
	int dy[4] = { 1,1,0,0 };
	int nx, ny, popCount=1;

	while (popCount > 0) {
		popCount = 0;

		//board�ѹ� �ȱ�
		for (int x = 0; x < m-1; x++) {
			for (int y = 0; y < n-1; y++) {
				bool pop = true;
				//4��� Ȯ��
				for (int idx = 0; idx < 4; idx++) {
					char curFriend = board[x].at(y);
					nx = x + dx[idx];
					ny = y + dy[idx];
					char newFriend = board[nx].at(ny);

					//��ҹ��� ���� X, ����� �ٸ���
					if (tolower(curFriend) != tolower(newFriend) || curFriend == ' ' || newFriend == ' ') {
						pop = false;
						break;
					}
				}

				//��� ���� ��������
				if (pop) {
					popCount++;
					//4�������� �ҹ���ȭ
					for (int index = 0; index < 4; index++) {
						int nnx = nx + dx[index];
						int nny = ny + dy[index];
						if ((board[nnx].at(nny) >= 'A') && (board[nnx].at(nny) <= 'Z')) //�빮������� ī��Ʈ�� ����
							board[nnx].at(nny) = tolower(board[nnx].at(nny)); //�������� nx�� ny�� ���� �ڸ��� ���ƿ��ϱ�?
					}
				}
			}
		}

		//�Ͷ߸���
		for (int cx = 0; cx < m; cx++) {
			for (int cy = 0; cy < n; cy++) {
				if ((board[cx].at(cy) >= 'a') && (board[cx].at(cy) <= 'z')) {
					board[cx].at(cy) = ' ';
					answer++;
				}
			}
		}

		//������ �ٴ����� ������
		//�ε��� �����ؾ��ؼ� �Ӹ��� �� �ȱ׷���.. . �� �ʿ�
		//���Ⱑ �ٽ�!?
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
// �����ϰ� ­������.. 4������� Ȯ���ϸ� �ٷ� �ҹ��ڷ� ����Բ� �ϸ� �ߺ��ڵ尡 ����

int main(void)
{
	//12
	cout << "������� �� �� : " << solution(6, 2, { "DD", "CC", "AA", "AA", "CC", "DD" }) << "\n" << endl;
	//8
	cout << "������� �� �� : " << solution(8, 2, { "FF", "AA", "CC", "AA", "AA", "CC", "DD", "FF" }) << "\n" << endl;
	//24
	cout << "������� �� �� : " << solution(5, 6, { "AAAAAA", "BBAATB", "BBAATB", "JJJTAA", "JJJTAA" }) << "\n" << endl;
	
	return 0;
}