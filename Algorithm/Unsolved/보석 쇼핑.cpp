// https://programmers.co.kr/learn/courses/30/lessons/67258
// map, 해설보니까 two pointer

#include <string>
#include <vector>
#include <set>

using namespace std;

// time complexity가 기준에 못 미침

vector<int> solution(vector<string> gems) {
	vector<int> answer;
	set<string> gemset;

	for (string s : gems)
		gemset.insert(s);

	for (int j = gemset.size(); j <= gems.size(); j++) {//크기 j
		for (int i = 0; (i + j-1) < gems.size(); i++) {//시작 인덱스 i

			set<string> temp;
			for (int k = i; k < i + j; k++) {
				temp.insert(gems[k]);
			}

			if (temp.size() == gemset.size()) {
				answer.push_back(i + 1);
				answer.push_back(i + j);
				return answer;
			}
		}
	}
}

int main() {
	//solution({ "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" });
	solution({ "ZZZ", "YYY", "NNNN", "YYY", "BBB" });
}