// https://programmers.co.kr/learn/courses/30/lessons/64065
// 파싱, 차집합?

#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

vector<string> tokenize_getline(const string& data, const char delimiter = ' ') {
	vector<string> result;
	string token;
	stringstream ss(data);

	while (getline(ss, token, delimiter)) {
		result.push_back(token.substr(2, token.size()));
	}
	return result;
}

bool cmp(vector<int> &a, vector<int>& b) {
	return a.size() < b.size();
}

bool cmp2(int &a, int & b) {
	return a < b;
}

vector<int> solution(string s) {
	vector<int> answer;
	vector<int> tuple;

	//parsing하여 vector에 넣기
	s = s.substr(0, s.length() - 2);
	vector<string> t = tokenize_getline(s, '}');
	vector<vector<int>> tt;
	for (int i = 0; i < t.size(); i++) {
		vector<int> result;
		stringstream sst(t[i]);
		string token;

		while (getline(sst, token, ',')) {
			result.push_back(stoi(token));
		}
		tt.push_back(result);
	}

	//vector 크기 오름차순 정렬
	sort(tt.begin(), tt.end(), cmp);

	//차집합 원소 찾아서 저장
	answer.push_back(tt[0][0]);
	for (int i = 1; i < tt.size(); i++) { //원소개수만큼
		for (int j = 0; j < answer.size(); j++) { //발견한 원소 개수만큼
			vector<int>::iterator it;
			it = find(tt[i].begin(), tt[i].end(), answer[j]);
			tt[i].erase(it);
		}
		answer.push_back(tt[i][0]);
	}

	return answer;
}

int main() {
	solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");
	solution("{{2},{2,2},{2,2,2},{2,2,2,2},{2,2,2,2,2}}");
}
//차집합을 erase로 구현해보았다!