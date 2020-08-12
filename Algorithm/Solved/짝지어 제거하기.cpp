// https://programmers.co.kr/learn/courses/30/lessons/12973
// stack

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
	int answer = 0;
	stack<char> numStack;

	for (int i = 0; i < s.length(); i++) {
		if (numStack.size() >= 1 && s[i] == numStack.top())
			numStack.pop();
		else numStack.push(s[i]);
		if (numStack.empty() && i == s.length() - 1) return 1;
	}
	return 0;
}

int main() {
	solution("baabaa");
	solution("cdccdc");
}