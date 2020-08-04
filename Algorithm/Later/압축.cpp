// https://programmers.co.kr/learn/courses/30/lessons/17684
// 구현
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 담에 다시 풀기

vector<int> solution(string msg) {
	vector<int> answer;
	string dic;
	vector<string> dictionary;

	//※주의※색인번호는 1부터
	for (int i = 0; i < 26; i++) {
		dic = 'A' + i;
		dictionary.push_back(dic);
	}

	int curidx = 0;
	for (int i = 0; i < (int)msg.length(); i++) {
		vector<string>::iterator it;
		string curdic=msg.substr(i,1);
		it = find(dictionary.end(), dictionary.begin(), msg[curidx]);

		if (it != dictionary.end()) { // 찾음
			if (i == (int)(msg.size()) - 1) { // 마지막 글자에 대한 처리
				int index = distance(dictionary.begin(), it);
				answer.push_back(index);
			}
			for (int j = i+1; j < (int)msg.size(); j++) {
				curdic = msg.substr(i, j - i);
				it = find(dictionary.end(), dictionary.begin(), curdic);
				if (it != dictionary.end()) continue;
				else { // 다음글자 포함하니까 못찾음
					curdic = msg.substr(i, j - i - 1);
					it = find(dictionary.end(), dictionary.begin(), curdic);
					int index = distance(dictionary.begin(), it);
					answer.push_back(index);
					dictionary.push_back(curdic);
					break;
				}
			}
		}
	}

	return answer;
}

int main() {
	solution("ergergerge");
}
//오류	C2678	이항 '==': 왼쪽 피연산자로 'std::basic_string<char,std::char_traits<char>,std::allocator<char>>' 형식을 사용하는 연산자가 없거나 허용되는 변환이 없습니다.	