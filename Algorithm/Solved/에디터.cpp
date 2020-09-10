// https://www.acmicpc.net/problem/1406
// stack

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

// 찾아보니까 list가 더 편한듯

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	stack<char> cursorLeft, cursorRight;

	string initString;
	cin >> initString;
	int N;
	cin >> N;
	for (int i = 0; i < initString.length(); i++) {
		cursorLeft.push(initString.at(i));
	}

	for (int n = 0; n < N; n++) {
		char c;
		cin >> c;
		switch (c) {
		case 'L':
			if (!cursorLeft.empty()) {
				cursorRight.push(cursorLeft.top());
				cursorLeft.pop();
			}
			break;
		case 'D':
			if (!cursorRight.empty()) {
				cursorLeft.push(cursorRight.top());
				cursorRight.pop();
			}
			break;
		case 'B':
			if (!cursorLeft.empty()) {
				cursorLeft.pop();
			}
			break;
		case 'P':
			char inputChar;
			cin >> inputChar;
			cursorLeft.push(inputChar);
			break;
		}
	}
	while(!cursorLeft.empty()){
		cursorRight.push(cursorLeft.top());
		cursorLeft.pop();
	}
	while (!cursorRight.empty()) {
		cout << cursorRight.top();
		cursorRight.pop();
	}
}