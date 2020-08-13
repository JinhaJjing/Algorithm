// https://programmers.co.kr/learn/courses/30/lessons/12983
// dp

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//dp라고 생각하기가 힘듦
//맞왜틀..^^

int solution(vector<string> strs, string t)
{
	int answer = 0;
	int dp[20000];

	for (int i = 0; i < t.size(); i++) {
		dp[i] = t.size() + 1;
		for (int j = 0; j < strs.size(); j++) {
			bool contains = true;

			for (int k = strs[j].size() - 1, index = i; index >= 0 && k >= 0; k--, index--) {
				if (strs[j][k] != t[index]) {
					contains = false;
					break;
				}
			}

			if (contains) {
				if (i - (strs[j].size() - 1) == 0) dp[i] = 1;
				else dp[i] = dp[i - strs[j].size()] + 1 < dp[i] ? dp[i - strs[j].size()] + 1 : dp[i];
			}
		}
	}

	answer = dp[t.size() - 1];
	if (answer >= t.size() + 1) {
		answer = -1;
	}

	return answer;
}

int main() {
	solution({ "ba", "na", "n", "a" }, "banana");
}