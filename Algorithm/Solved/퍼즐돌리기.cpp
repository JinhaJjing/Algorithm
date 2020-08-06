//구현

#include <iostream>
using namespace std;

int room[101][101] = { 0, };
int copyRoom[101][101] = { 0, };

typedef struct { int y, x; } Dir;
Dir moveDir[4] = { {0, 1},{1, 0}, {0, -1},{-1, 0} }; //시계방향

int main()
{
	int R, C, n;
	cin >> R >> C >> n;

	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			cin >> room[i][j];

	int a, b, c, d;
	for (int turnCnt = 0; turnCnt < n; turnCnt++) {
		cin >> a >> b >> c >> d;

		//복사본 생성
		for (int i = 1; i <= R; i++)
			for (int j = 1; j <= C; j++)
				copyRoom[i][j] = room[i][j];

		//turn
		int y = a;
		int x = b;

		for (int k = 0; k < 4; k++) {
			while (true) {
				int nextY = y + moveDir[k].y;
				int nextX = x + moveDir[k].x;

				if (!(1 <= nextY && nextY <= c && 1 <= nextX && nextX <= d)) break;
				if (nextY < a || nextX < b) break;

				room[nextY][nextX] = copyRoom[y][x];

				y = nextY;
				x = nextX;
			}
		}
	}

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << room[i][j] << " ";
		}
		cout << "\n";
	}
}