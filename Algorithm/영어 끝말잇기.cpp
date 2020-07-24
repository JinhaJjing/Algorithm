// https://programmers.co.kr/learn/courses/30/lessons/12981
// ±¸Çö

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<string> words) {
	vector<int> answer;

	for (int i = 0; i < words.size();i++) {
		if (i != 0) {
			string lalphabet = words[i-1].substr(words[i-1].length() - 1, words[i-1].length());
			string falphabet = words[i].substr(0, 1);
			if (lalphabet != falphabet) {
				if (((i + 1) % n) == 0) answer.push_back(n);
				else answer.push_back((i + 1) % n);
				answer.push_back(i / n+1);
				return answer;
			}
			for(int j=0;j<i;j++){
				if (words[j] == words[i]) {
					if (((i + 1) % n) == 0) answer.push_back(n);
					else answer.push_back((i + 1) % n);
					answer.push_back(i / n + 1);
					return answer;
				}
			}
		}
	}
	return { 0,0 };
}//¸·Â«