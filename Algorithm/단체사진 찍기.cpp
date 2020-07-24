// https://programmers.co.kr/learn/courses/30/lessons/1835
// 순열

#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
	int answer = 0;
	vector<char> friends = { 'A','C','F','J','M','N','R','T' };

	// 모든 경우의수를 고려. 될때마다 answer+1
	//8중 for문을 하거나 재귀하거나 해야하므로 막막..
	//stl의 next_permutation함수를 알게됨

	do {
		bool satisfy = true;

		for (int i = 0; i < n; i++) {
			char cmp = data[i].at(3); // substr말고 at을 씀
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