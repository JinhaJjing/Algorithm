// https://programmers.co.kr/learn/courses/30/lessons/42579
// map

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b) {
	return a.second > b.second;
}

bool cmp2(pair<int, int> a, pair<int, int> b) {
	return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	map<string, int> m;

	for (int i = 0; i < genres.size(); i++) {
		m[genres[i]]+=plays[i];
	}

	vector<pair<string, int>> music;
	map<string, int>::iterator it;
	
	for (it = m.begin(); it != m.end(); it++) {
		music.push_back(make_pair(it->first, it->second));
	}

	sort(music.begin(), music.end(),cmp); // 오름차순 정렬

	vector<pair<int, int>> candidate; //index, plays
	for (int i = 0; i < music.size(); i++) {
		string genre = music[i].first;

		for (int j = 0; j < genres.size(); j++) {
			if (!(genres[j].compare(genre))) //같으면
				candidate.push_back(make_pair(j, plays[j]));
		}
		sort(candidate.begin(), candidate.end(), cmp2);

		int best = 0;
		for (int k = 0; k < candidate.size(); k++) {
			if (best < 2) { // 2개까지만 수록
				answer.push_back(candidate[k].first);
				best++;
			}
			else break;
		}
		candidate.clear();
	}

	return answer;
}

int main() {
	vector<string> v = {"classic", "pop", "classic", "classic", "pop"};
	vector<int> a = { 500,600,150,800,2500 };
	solution(v,a);
}