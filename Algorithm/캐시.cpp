// https://programmers.co.kr/learn/courses/30/lessons/17680
// vector find, erase, remove등

#include <string>
#include <vector>
#include <cstring>

using namespace std;

int find_match_index(vector<string> cityCache, string city) {
	for (int i = 0; i < city.length(); i++) {
		city[i] = tolower(city.at(i));
	}
	for (int j = 0; j < cityCache.size();j++) {
		for (int i = 0; i < cityCache[j].length(); i++) {
			cityCache[j][i] = tolower(cityCache[j].at(i));
		}
		if (!strcmp(cityCache[j].c_str(), city.c_str())) return j;
	}
	return -1;
}

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	vector<string> cityCache;

	for (int i = 0; i < cities.size(); i++) {
		if (cacheSize == 0) answer += 5;
		else if (find_match_index(cityCache, cities[i])!=-1) { // 이미 담긴 도시
			cityCache.erase(cityCache.begin()+ find_match_index(cityCache, cities[i])); // hit한 값을 가장 최근 사용으로 올려줌
			cityCache.push_back(cities[i]);
			answer += 1;
		}
		else { 
			if (cityCache.size() >= cacheSize) {
				cityCache.erase(cityCache.begin()); // 못담는 경우는 가장 예전에 사용한 값 삭제하고 담음
			}
			cityCache.push_back(cities[i]);
			answer += 5;
		}
	}
	return answer;
}
// iterator를 사용한 find함수를 쓰는 방법을 익혀서 써먹어도 됨

int main() {
	solution(3, { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA" });
	solution(3, { "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul" });
	solution(0, { "Jeju", "Pangyo", "Seoul", "NewYork", "LA" });
	solution(2, { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco","Seoul","Rome", "Paris", "Jeju", "NewYork", "Rome" });
	solution(5, { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome" });
}