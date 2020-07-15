#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = s.length();

	for (int i = 1; i <= s.length() / 2; i++) {
		int count = 1;
		int curLength = s.length();
		string stdstr, curstr;
		stdstr = s.substr(0, i);
		for (int curposition = i; curposition < s.length(); curposition+=i) {
			curstr = s.substr(curposition, i);

			if (!(stdstr.compare(curstr))) //���ڿ� ������
				count++;
			else { //���ڿ� �ٸ���
				stdstr = curstr; //���ο� ���ع��ڿ�
				if (count >= 2) {
					curLength = curLength - i * (count - 1) + to_string(count).length();// count������ ���̸�ŭ
				}
				count = 1;
			}

			if (curposition + i >= s.length()) {
				if (count >= 2) {
					curLength = curLength - i * (count - 1) + to_string(count).length();// count������ ���̸�ŭ
				}
			}

			answer = (answer > curLength) ? curLength : answer;
		}
	}
	return answer;
}

int main() {
	string s = "abcabcdede";

	solution(s);
}