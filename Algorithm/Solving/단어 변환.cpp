// https://programmers.co.kr/learn/courses/30/lessons/43163
// dfs

#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(int cnt, vector<string> words, vector<bool> visited, string begin, string target) {
	for (int i = 0; i < words.size(); i++) {
		if (!visited[i]) {
			int sameDigits = 0;
			for (int j = 0; j < begin.length(); j++)
				if (begin[j] != words[i][j])
					sameDigits++;
			if (sameDigits == 1) {
				//target완성
				if (target == words[i] && answer > cnt + 1) {
					answer = cnt + 1;
					return;
				}
				//target미완성
				else {
					//단어를 사용했다 체크하고 재귀
					visited[i] = true;
					dfs(cnt + 1);
					//함수를 나온경우 단어사용여부 해제
					visited[i] = false;
				}
			}
		}
	}

	answer = cnt < answer ? cnt : answer;
}


int solution(string begin, string target, vector<string> words) {
	vector<bool> visited(50);

	for (int i = 0; i < words.size(); i++) {
		if (!visited[i]) {
			int count = 0;
			dfs(count, words, visited);
		}
	}

	return answer;
}