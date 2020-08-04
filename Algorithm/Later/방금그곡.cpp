// https://programmers.co.kr/learn/courses/30/lessons/17683
// 구현

//'#'을 고려하지 않고 짜다가 나중에 알고 던짐
//string을 다룰때는 함수들을 잘 이용하자. 가령 여기서는 replace함수를 사용하면 #을 관리하기에 매우 편리함

#include <string>
#include <vector>
#include <cstring>
#include <string.h>

using namespace std;

string solution(string m, vector<string> musicinfos) {
	string answer = "(None)";
	vector<pair<string, string>> music;
	vector<int> time;

	// musicinfos를 parsing
	for (int i = 0; i < musicinfos.size(); i++) {
		string t1h, t1m, t2h, t2m;
		t1h=musicinfos[i].substr(0, 2);
		t1m=musicinfos[i].substr(3, 2);
		t2h=musicinfos[i].substr(6, 2);
		t2m=musicinfos[i].substr(9, 2);
		if (t1m <= t2m)
			time.push_back((stoi(t2h) - stoi(t1h)) * 60 + stoi(t2m) - stoi(t1m));
		else
			time.push_back((stoi(t2h) - stoi(t1h)) * 60 -(stoi(t1m) - stoi(t2m)));

		musicinfos[i] = musicinfos[i].substr(12, musicinfos[i].size());

		for (int j = 0; j < musicinfos[i].size(); j++) {
			if (musicinfos[i].at(j) == ',') {
				string title = musicinfos[i].substr(0, j);
				string melody = "";
				string basemelody = musicinfos[i].substr(j + 1);
				int basemeldoysize = 0;

				for (int l = 0; l < basemelody.size(); l++) {
					if (basemelody[l] != '#')
						basemeldoysize++;
				}

				// 재생된만큼의 멜로디 저장
				int repeat1 = time[i] / basemeldoysize;
				int repeat2 = time[i] % basemeldoysize;
				if (repeat1 > 0) {
					for (int k = 0; k < repeat1; k++)
						melody += basemelody;
					melody += basemelody.substr(0, repeat2);
				}
				else {
					melody = basemelody.substr(0, repeat2);
				}
				music.push_back(make_pair(title, melody));
				break;
			}
		}
	}

	// 먼저 입력된게 먼저 벡터에 들어감
	// 멜로디의 길이가 재생된 길이 
	int maxlength = 0;
	for (int i = 0; i < music.size(); i++) {
		char * a=strstr((char *)music[i].second.c_str(), (char *)m.c_str());
		if (a != NULL) { // 존재
			if (a[m.length()] != '#') {
				if (maxlength < music[i].second.size()) {
					maxlength = music[i].second.size();
					answer = music[i].first;
				}
			}
		}
	}

	return answer;
}

int main() {
	//solution("ABCDEFG", { "12:00,12:14,HELLO,CDEFGAB","13:00,13:05,WORLD,ABCDEF" });
	solution("ABCD#", { "12:00,12:04,HELLO,ABCD#","13:00,13:05,WORLD,ABCDEF" });
	solution("CDCDF", { "12:00,12:14,HELLO,CDCDCDF","13:00,13:05,WORLD,ABCDEF" });
}