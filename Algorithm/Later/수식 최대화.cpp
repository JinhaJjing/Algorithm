// https://programmers.co.kr/learn/courses/30/lessons/67257
// stack, 완전탐색/순열

#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;


// 뭐가 틀린건지 못찾겠ㄷ ㅏ 꾀 꼬ㄹ ㅣ


int findOperationPrior(vector<char> operations, char operation) {
	for (int i = 0; i < operations.size();i++) {
		if (operations[i]==operation)
			return i;
	}
}

long long solution(string expression) {
	long long answer = 0;
	vector<char> operations = { '*','+','-' };
	stack<char> op;
	stack<int> operand;

	do {
		// 숫자랑 연산자 쪼개서 stack에 담기
		string num = "";
		for (char c : expression) {
			if (c == '*' || c == '-' || c == '+') {
				operand.push(stoi(num));
				num = "";

				// 연산자 인덱스가 큰거부터 계산
				while (!op.empty() && findOperationPrior(operations, c) >= findOperationPrior(operations, op.top())) {
					char o = op.top();
					op.pop();
					int o2 = operand.top();
					operand.pop();
					switch (o) {
					case '+': operand.top() += o2;
						break;
					case '-': operand.top() -= o2;
						break;
					case '*': operand.top() *= o2;
						break;
					}
				}
					
				//우선순위에 따라 스택에 push
				op.push(c);
			}
			else {
				num += c;
			}
		}

		operand.push(stoi(num));
		// 마지막 연산자 털이
		while (!op.empty()) {
			char o = op.top();
			op.pop();
			int o2 = operand.top();
			operand.pop();
			switch (o) {
			case '+': operand.top() += o2;
				break;
			case '-': operand.top() -= o2;
				break;
			case '*': operand.top() *= o2;
				break;
			}
		}

		// answer업데이트
		if (abs(operand.top())>abs(answer)) {
			answer = abs(operand.top());
		}
		// 연산자 우선순위가 곧 operations순서
	} while (next_permutation(operations.begin(), operations.end()));

	return answer;
}

int main() {
	cout << solution("50*6-3*2") << endl;
	cout << solution("100-200*300-500+20") << endl;
}