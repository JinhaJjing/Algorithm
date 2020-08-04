// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWIeV9sKkcoDFAVH&&#none
// direction

#include<iostream>
#include<math.h>
using namespace std;

int cogwheel[5][9];
bool c1 = false, c2 = false, c3 = false;

void rotateCogwheel(int wheelNum, int direction);
void check();
void rotate(int wheelNum, int dir);

void rotateCogwheel(int wheelNum, int direction) {
	check();
	rotate(wheelNum, direction);
	switch (wheelNum)
	{
	case 1:
		if (c1) {
			rotate(wheelNum + 1, (-1) * direction);
			if (c2) {
				rotate(wheelNum + 2, direction);
				if (c3) rotate(wheelNum + 3, (-1) * direction);
			}
		}
		break;
	case 2:
		if (c1 && c2) {
			rotate(wheelNum - 1, (-1) * direction);
			rotate(wheelNum + 1, (-1) * direction);
			if (c3) rotate(wheelNum + 2, direction);
		}
		else if (c1) rotate(wheelNum - 1, (-1) * direction);
		else if (c2) {
			rotate(wheelNum + 1, (-1) * direction);
			if (c3) rotate(wheelNum + 2, direction);
		}
		break;
	case 3:
		if (c2 && c3) {
			rotate(wheelNum - 1, (-1) * direction);
			rotate(wheelNum + 1, (-1) * direction);
			if (c1) rotate(wheelNum - 2, direction);
		}
		else if (c3) rotate(wheelNum + 1, (-1) * direction);
		else if (c2) {
			rotate(wheelNum - 1, (-1) * direction);
			if (c1) rotate(wheelNum - 2, direction);
		}
		break;
	case 4:
		if (c3) {
			rotate(wheelNum - 1, (-1) * direction);
			if (c2) {
				rotate(wheelNum - 2, direction);
				if (c1) rotate(wheelNum - 3, (-1) * direction);
			}
		}
		break;
	default:
		break;
	}
}

void check() {
	if (cogwheel[1][3] != cogwheel[2][7]) c1 = true; else c1 = false;
	if (cogwheel[2][3] != cogwheel[3][7]) c2 = true; else c2 = false;
	if (cogwheel[3][3] != cogwheel[4][7]) c3 = true; else c3 = false;
}

void rotate(int wheelNum, int dir) {
	if (dir == 1) {
		int temp = cogwheel[wheelNum][8];
		for (int i = 8; i > 1; i--)  cogwheel[wheelNum][i] = cogwheel[wheelNum][i - 1];
		cogwheel[wheelNum][1] = temp;
	}
	else {
		int temp = cogwheel[wheelNum][1];
		for (int i = 1; i < 8; i++) cogwheel[wheelNum][i] = cogwheel[wheelNum][i + 1];
		cogwheel[wheelNum][8] = temp;
	}
}

int main() {
	int T, K, answer;
	cin >> T;  // �� �׽�Ʈ�� ����
	for (int t = 1; t <= T; t++) { // �� �׽�Ʈ ���̽��� ������ŭ �ݺ�
		cin >> K; // �ڼ� ȸ�� Ƚ��

		memset(cogwheel, 0, sizeof(cogwheel));
		answer = 0;
		for (int i = 1; i <= 4; i++) { // �ڼ� 8�� ���� �ڼ�����
			for (int j = 1; j <= 8; j++)
				cin >> cogwheel[i][j];
		}

		for (int i = 0; i < K; i++) { // K�ٿ� ��� �ڼ��� ȸ������
			int rotateWheelNum, direction;
			cin >> rotateWheelNum >> direction;
			rotateCogwheel(rotateWheelNum, direction); // ȸ�� �Լ� ȣ��
		}
		answer = cogwheel[1][1] * 1 + cogwheel[2][1] * 2 + cogwheel[3][1] * 4 + cogwheel[4][1] * 8;
		cout << "#" << t << ' ' << answer << '\n'; // �׽�Ʈ ���̽��� ��ȣ�� k���� ȸ������ ���
	}
	return 0;
}