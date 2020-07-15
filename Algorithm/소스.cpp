#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	vector<string> new_skill_trees;

	for (int i = 0; i < skill_trees.size(); i++) {
		string s = skill_trees[i];
		string temp = "";
		for (int j = 0; j < s.length(); j++) {//B,A,C,D,E
			bool exist = false;
			for (int k = 0; k < skill.length(); k++) {
				if (s[j] == skill[k]) exist = true;//B�� CBD�� ������
			}
			if (exist) temp += s[j]; // B,C,D
		}
		if (temp.length() == 0) answer++;
		else new_skill_trees.push_back(temp);
	}

	for (auto s : new_skill_trees) {
		int j;
		for (j =0 ; j < s.length(); j++)
			if (skill[j] != s[j]) break; // Ʋ������
		if (j== s.length()) answer++; //�� �ôµ� �´¹����̴�
	}

	return answer;
}

int main() {
	string skill;
	vector<string> skill_trees;
	skill = "CBD";
	skill_trees = { "BACDE","CBADF","AECB","BDA" };

	cout<<solution(skill, skill_trees);
}