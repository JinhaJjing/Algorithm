// https://programmers.co.kr/learn/courses/30/lessons/49994
// 다차원 배열 or class

#include <string>

using namespace std;

//각 좌표별 상하좌우 방향으로 이동했는지의 여부를
//class의 멤버로 판단했다

class Coor {
public:
	int x, y;
	bool U=false, D=false, R=false, L=false;
};

int solution(string dirs) {
	int answer = dirs.length();
	Coor m[11][11];

	int cx = 5;
	int cy = 5;
	int nx = cx, ny = cy;

	for (int i = 0; i < dirs.length(); i++) {

		switch (dirs[i]) {
		case 'U':
			if (cx - 1 >= 0) {
				nx = cx - 1;
				if (m[cx][cy].U || m[nx][ny].D)
					answer--;
				m[cx][cy].U = true;
				cx = nx;
			}
			else answer--;
			break;
		case 'D':
			if (cx + 1 <= 10) {
				nx = cx + 1;
				if (m[cx][cy].D || m[nx][ny].U)
					answer--;
				m[cx][cy].D = true;
				cx = nx;
			}
			else answer--;
			break;
		case 'L':
			if (cy - 1 >= 0) {
				ny = cy - 1;
				if (m[cx][cy].L || m[nx][ny].R)
					answer--;
				m[cx][cy].L = true;
				cy = ny;
			}
			else answer--;
			break;
		case 'R':
			if (cy + 1 <= 10) {
				ny = cy + 1;
				if (m[cx][cy].R || m[nx][ny].L)
					answer--;
				m[cx][cy].R = true;
				cy = ny;
			}
			else answer--;
			break;
		}
	}

	return answer;
}

int main() {
	//solution("LULLLLLLU");
	//solution("LLLLRLRLRLL");//6
	//solution("UUUUDUDUDUUU");//6
	//solution("LURDLURDLURDLURDRULD");//7
	solution("RRRRRRRRRRRRRRRRRRRRRUUUUUUUUUUUUULU");//11
}