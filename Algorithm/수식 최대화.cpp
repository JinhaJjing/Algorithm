// https://programmers.co.kr/learn/courses/30/lessons/67257
// stack, ����Ž��/����

#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;


// ���� Ʋ������ ��ã�ڤ� �� �� ���� ��


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
		// ���ڶ� ������ �ɰ��� stack�� ���
		string num = "";
		for (char c : expression) {
			if (c == '*' || c == '-' || c == '+') {
				operand.push(stoi(num));
				num = "";

				// ������ �ε����� ū�ź��� ���
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
					
				//�켱������ ���� ���ÿ� push
				op.push(c);
			}
			else {
				num += c;
			}
		}

		operand.push(stoi(num));
		// ������ ������ ����
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

		// answer������Ʈ
		if (abs(operand.top())>abs(answer)) {
			answer = abs(operand.top());
		}
		// ������ �켱������ �� operations����
	} while (next_permutation(operations.begin(), operations.end()));

	return answer;
}

int main() {
	cout << solution("50*6-3*2") << endl;
	cout << solution("100-200*300-500+20") << endl;
}