// https://programmers.co.kr/learn/courses/30/lessons/42842
// 완전탐색

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
	vector<int> answer;
	int total = brown + yellow;
	
	for (int w = 3; w <= total / 3; w++) {
		for (int h = 3; h <= total / 3; h++) {
			if (w*h == total && w >= h) {
				if ((w - 2)*(h - 2) == yellow) {
					answer.push_back(w);
					answer.push_back(h);
					return answer;
				}
			}
		}
	}
}