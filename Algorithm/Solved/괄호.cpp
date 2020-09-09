// https://www.acmicpc.net/problem/9012
// stack

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

bool checkParenthesis(string s) {
	stack<string> stack;
	for (int i = 0; i < s.length(); i++) {
		string p = s.substr(i, 1);
		if (p == "(") stack.push(p);
		else {
			if(!stack.empty()) stack.pop();
			else return false;
		}
	}
	if (stack.size() > 0)
		return false;
	else return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int n = 0; n < N; n++) {
		string s;
		cin >> s;
		if(checkParenthesis(s)) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}