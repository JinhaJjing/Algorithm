// https://programmers.co.kr/learn/courses/30/lessons/42578
// hash(map)

#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;
	map<string, int> m;

	for (vector<string> c: clothes) {
		m[c[1]]++;
	}

	map<string,int>::iterator it;
	for (it = m.begin(); it != m.end(); it++) {
		answer *= (it->second + 1);
	}

	return answer-1;
}
//map자체는 쉬웠으나 경우의수 구하는게 더 어려웠음