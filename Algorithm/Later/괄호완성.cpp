// 스택

#include <iostream>
#include <stack>
#include <string>

// TODO : 스택(poor skill now)

using namespace std;

stack<char> ptStack;

int main() {
	int N, cnt = 0;
	cin >> N;

	string input, output;
	cin >> input;

	char temp;
	for (int i = 0; i < input.length(); i++) {
		temp = input[i];

		if (temp == '(')
			ptStack.push(temp);
		else if (temp == ')') {
			if (!ptStack.empty() && ptStack.top() == '(') {
				ptStack.pop();
				output += "()";
				ptStack.pop();
			}
			else {
				ptStack.push('(');
				ptStack.push(temp);
				output += "(";
				cnt++;
			}
		}
	}

	while (!ptStack.empty()) {
		char temp = ptStack.top();
		ptStack.pop();
		if (temp == '(')
			output += ")";
	}

	cout << cnt << "\n" << output << endl;
}