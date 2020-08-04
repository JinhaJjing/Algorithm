// https://programmers.co.kr/learn/courses/30/lessons/42588
// 스택(이래서 풀었는데 스택 필요없음)

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
	vector<int> answer;

	for (int i = 0; i < heights.size(); i++) {
		int curh = heights[i];
		if (i == 0) answer.push_back(0);
		else {
			for (int j = i - 1; j >= 0; j--) {
				if (heights[j] > curh) {
					answer.push_back(j + 1);
					break;
				}
				else {
					if(j==0) answer.push_back(0);
				}
			}
		}
	}

	return answer;
}
//스카이스크래퍼가 조금 생각나는 간단한 문제