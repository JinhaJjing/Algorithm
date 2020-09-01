// https://programmers.co.kr/learn/courses/30/lessons/12987
// time complexity

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
	int answer = 0;
	int cnt = 0;

	sort(A.begin(), A.end(), greater<int>());
	sort(B.begin(), B.end(), greater<int>());

	for (int i = 0; i < A.size(); i++) {
		for (int j = cnt; j < B.size(); j++) {
			if (A[i] < B[j]) {
				cnt++;
				answer++;
				break;
			}
		}
	}
	return answer;
}
