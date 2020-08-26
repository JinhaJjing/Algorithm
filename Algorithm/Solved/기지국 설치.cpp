// https://programmers.co.kr/learn/courses/30/lessons/12979
// 구현

#include <iostream>
#include <vector>

using namespace std;

//연속된 칸 수 체크...가 아닌가?
//한칸만 떨어져있으면 어떡하나 싶었는데
//아니었음. 그런 경우가 있을리없음.
//전달안되는 칸수 세면 됨~

int solution(int n, vector<int> stations, int w)
{
	int answer = 0;

	int start = 0;
	for (int i = 0; i < stations.size(); i++) {
		int l = stations[i] - w - 1;
		int len = l - start;
		start = stations[i] + w; //5지만 - 연산 위해서

		if (len > 0) {
			answer += len / (2 * w + 1);
			if ((len % (2 * w + 1)) != 0)
				answer += 1;
		}
	}

	int len = n - stations[stations.size() -1] - w;
	if (len > 0) {
		answer += len / (2 * w + 1);
		if ((len % (2 * w + 1)) != 0)
			answer += 1;
	}

	return answer;
}

int main() {
	//solution(11, { 4, 11 }, 1);
	solution(16, { 9 }, 2);
}