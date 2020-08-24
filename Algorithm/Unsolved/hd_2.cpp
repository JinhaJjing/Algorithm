// hd_2

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

/*
int solution(vector<string> ip_addrs, vector<string> langs, vector<int> scores) {
	int good_participants=0;

	vector<string>::iterator iter;
	vector<string> ip;

	for (int i = 0; i < langs.size(); i++) {
		iter= find(ip.begin(), ip.end(), ip_addrs[i]);
		if(iter==ip.end())
			ip.push_back(ip_addrs[i]);
	}

	int size = ip.size();
	int* count = new int[size]();
	for (int i = 0; i < langs.size(); i++) {
		for (int j = 0; j < ip.size(); j++) {
			if (ip[j].compare(ip_addrs[i]) == 0)//같다
				count[j] += 1;
		}
	}

	int student = ip_addrs.size();
	bool* students = new bool[student];
	string language = "0";

	for (int i = 0; i < ip.size(); i++) {
		if (count[i] >= 4) {
			for (int j = 0; j < ip_addrs.size(); j++) {
				if (ip[i].compare(ip_addrs[j]) == 0)
					students[j] = false;
			}
		}
		else if (count[i] == 3) {
			for (int j = 0; j < ip_addrs.size(); j++) {
				if (ip[i].compare(ip_addrs[j]) == 0) {
					if (language.compare("0"))
						language = langs[j];
					else if (language.compare(langs[j]) != 0)//다르면
				}
			}
		}
	}

	delete[] count;
	return good_participants;
}
*/

int solution(vector<string> ip_addrs, vector<string> langs, vector<int> scores) {
	
	//조건1 : 같은IP4명이상 = 모두 부정
	//조건2 : 같은IP3명&모두 같은 언어군 = 3명 부정
	//조건3 : 같은IP2명&모두 같은 언어군&성적 동일 = 2명 부정

	int answer = 0;
	vector<string> language = { "C","C++","C#","Java","JavaScript","Python3" };
	vector<int> ischeated(100000);
	vector<vector<int>> sameIP(100000);
	map<string, int> m;

	for (int i = 0; i < ip_addrs.size(); i++) {
		if (m.find(ip_addrs[i]) != m.end())
			m[ip_addrs[i]]++;
	}

	for (int i = 0; i < ip_addrs.size(); i++) {
		if (m[ip_addrs[i]] >= 4)
			ischeated[i] = 1;
		else if (m[ip_addrs[i]] == 3) {

		}
		else if (m[ip_addrs[i]] == 2) {

		}
	}

	for (int i = 0; i < langs.size(); i++) {
		if (ischeated[i]) answer++;
	}
	return answer;
}

int main() {
	solution({ "5.5.5.5","155.123.124.111","10.16.125.0","155.123.124.111","5.5.5.5","155.123.124.111","10.16.125.0","10.16.125.0" }, { "Java","C++","Python3","C#","Java","C","Python3","JavaScript" }, { 264,197,373,45,294,62,373,373 });
	solution({ "7.124.10.0","7.124.10.0","0.0.0.0","7.124.10.0","0.0.0.0","7.124.10.0" }, { "C++","Java","C#","C#","C","Python3" }, { 314,225,45,0,55,400 });
}