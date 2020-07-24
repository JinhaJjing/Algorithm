// https://programmers.co.kr/learn/courses/30/lessons/1835
// ����

#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
int solution(int n, vector<string> data) {
	int answer = 0;
	vector<char> friends = { 'A','C','F','J','M','N','R','T' };

	// ��� ����Ǽ��� ���. �ɶ����� answer+1
	//8�� for���� �ϰų� ����ϰų� �ؾ��ϹǷ� ����..
	//stl�� next_permutation�Լ��� �˰Ե�

	do {
		bool satisfy = true;

		for (int i = 0; i < n; i++) {
			char cmp = data[i].at(3); // substr���� at�� ��
			int itv = data[i].at(4)-'0';
			int fidx, f2idx;

			for (int j = 0; j < friends.size(); j++) {
				if (friends[j] == data[i].at(0))
					fidx = j;
				if (friends[j] == data[i].at(2))
					f2idx = j;
			}

			switch (cmp) {
			case '=':
				if (abs(fidx - f2idx) - 1 != itv)
					satisfy = false;
				break;
			case '>':
				if (abs(fidx - f2idx) - 1 <= itv)
					satisfy = false;
				break;
			case '<':
				if (abs(fidx - f2idx) - 1 >= itv)
					satisfy = false;
				break;
			}

			if (!satisfy) break;
		}
		if (satisfy) answer++;

	} while (next_permutation(friends.begin(), friends.end()));

	return answer;
}

int main() {
	//vector<string> data = { "N~F=0","R~T>2" };
	vector<string> data = { "M~C<2", "C~M>1" };
	solution(2, data);
}