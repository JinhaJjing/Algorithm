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
					visited[i] = true;
					dfs(cnt + 1, words, visited, words[i],target);
					//함수를 호출하고 해당 단어는 선택해제
					visited[i] = false;
				}
			}
		}
	}
}

int solution(string begin, string target, vector<string> words) {
	vector<bool> visited(50);
	dfs(0, words, visited, begin, target);
	return answer;
}

int main() {
	solution("dog", "cat", { "dog","dag","cag","cat" });
}