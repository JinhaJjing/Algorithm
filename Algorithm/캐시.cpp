// https://programmers.co.kr/learn/courses/30/lessons/17680
// vector find, erase, remove��

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
		else if (find_match_index(cityCache, cities[i])!=-1) { // �̹� ��� ����
			cityCache.erase(cityCache.begin()+ find_match_index(cityCache, cities[i])); // hit�� ���� ���� �ֱ� ������� �÷���
			cityCache.push_back(cities[i]);
			answer += 1;
		}
		else { 
			if (cityCache.size() >= cacheSize) {
				cityCache.erase(cityCache.begin()); // ����� ���� ���� ������ ����� �� �����ϰ� ����
			}
			cityCache.push_back(cities[i]);
			answer += 5;
		}
	}
	return answer;
}
// iterator�� ����� find�Լ��� ���� ����� ������ ��Ծ ��

int main() {
	solution(3, { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA" });
	solution(3, { "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul" });
	solution(0, { "Jeju", "Pangyo", "Seoul", "NewYork", "LA" });
	solution(2, { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco","Seoul","Rome", "Paris", "Jeju", "NewYork", "Rome" });
	solution(5, { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome" });
}