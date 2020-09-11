// https://programmers.co.kr/learn/courses/30/lessons/64062
// time complexity

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> stones, int k) {
	int answer = 0;
	bool flag = false;

	while (1) {
		int curposition = -1;
		flag = false;
		int stsize = stones.size();

		while (curposition < stsize) { // �� ģ���� �ǳʴ� ����
			if (curposition == (stsize - 1)) {
				flag = true;
				break;
			}
			if (stones[curposition + 1] > 0) {
				flag = true;
				stones[curposition + 1]--;
				curposition++;
			}
			else {
				for (int j = 1; j <= k; j++) {
					if (curposition + j >= stones.size()) {
						flag = true;
						curposition = stsize - 1;
						break;
					}
					if (stones[curposition + j] > 0) {
						flag = true;
						stones[curposition + j]--;
						curposition += j;
						break;
					}
				}
			}

			if (!flag) break;
			else flag = false; // ����ؼ� �ǳʱ� ���� �ʱ�ȭ
		}

		if (!flag) // ���ǳ� ģ�� �߻�
			break;
		else answer++;
	}
	return answer;
}

int main() {
	solution({ 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 },3);
}