// https://programmers.co.kr/learn/courses/30/lessons/42888
// map, string parsing

#include <string>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> result;
	vector<string> userId;
	map<string, string> usersInfo; //id, name
	string action="", uid="", nickname="";

	for (int i = 0; i < record.size();i++) {
		//parsing
		int sl = record[i].length();
		for (int j = 0; j < sl; j++) {
			if (record[i][j] == ' ') {
				action = record[i].substr(0, j);
				record[i] = record[i].substr(j + 1, sl - j + 1);
				break;
			}
		}
		if (action == "Leave") uid = record[i];
		else {
			for (int j = 0; j < sl; j++) {
				if (record[i][j] == ' ') {
					uid = record[i].substr(0, j);
					record[i] = record[i].substr(j + 1, sl - j + 1);
					break;
				}
			}
			nickname = record[i];
		}

		if (action=="Enter") {
			userId.push_back(uid);
			usersInfo[uid] = nickname;
			result.push_back("님이 들어왔습니다.");
		}
		else if (action == "Leave") {
			userId.push_back(uid);
			result.push_back("님이 나갔습니다.");
		}
		else if (action == "Change") {
			usersInfo[uid] = nickname;
		}
	}

	for (int i = 0; i < result.size(); i++) {
		result[i] = usersInfo[userId[i]] + result[i];
	}

	return result;
}

int main() {
	solution({ "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" });
}
// c++에서 string parsing은 string.h의 strtok를 이용한다구한다..
// 컴파일오류나서 strtok_s로 바꾸고.. 인자도 바꿨는데
// 런타임오류나서 막혔음
// 찾아보니 stringstream을 사용한 예시들이 많다(편해보임)
// 어떻게 고쳐야하는지..
// 고민하다 무식하게 파싱했다!!