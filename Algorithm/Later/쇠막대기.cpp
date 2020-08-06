// https://programmers.co.kr/learn/courses/30/lessons/42585
// 스택

#include <string>
#include <vector>
#include <stack>

//TODO : 스택 hard

using namespace std;

int solution(string arrangement) {
	int answer = 0;
	stack<char> parenthesis;
	vector<char> state;

	for (int i = 0; i < arrangement.size(); i++) {
		if (arrangement[i] == '(')
			parenthesis.push(arrangement[i]);
		else {
			if (parenthesis.top() == '(') {//레이저랑 파이프 구별하기
				parenthesis.pop();
				state[i] = '*';//레이저
			}
		}
	}




	return answer;
}