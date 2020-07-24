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
			result.push_back("���� ���Խ��ϴ�.");
		}
		else if (action == "Leave") {
			userId.push_back(uid);
			result.push_back("���� �������ϴ�.");
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
// c++���� string parsing�� string.h�� strtok�� �̿��Ѵٱ��Ѵ�..
// �����Ͽ������� strtok_s�� �ٲٰ�.. ���ڵ� �ٲ�µ�
// ��Ÿ�ӿ������� ������
// ã�ƺ��� stringstream�� ����� ���õ��� ����(���غ���)
// ��� ���ľ��ϴ���..
// ����ϴ� �����ϰ� �Ľ��ߴ�!!