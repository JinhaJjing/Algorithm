// https://programmers.co.kr/learn/courses/30/lessons/42585
// 스택

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string arrangement;
	cin >> arrangement;

	int answer = 0;
	stack<char> parenthesis;

	for (int i = 0; i < arrangement.size(); i++) {
		if (arrangement[i] == '(')
			parenthesis.push(arrangement[i]);
		else {
			if (arrangement[i-1]=='(') {//레이저랑 파이프 구별하기
				parenthesis.pop();
				answer += (int)parenthesis.size();
			}
			else {
				parenthesis.pop();
				answer += 1;
			}
		}
	}

	cout << answer;

	return 0;
}