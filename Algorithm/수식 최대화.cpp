#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

long long solution(string expression) {
	long long answer = 0;
	vector<char> operations = { '+','-','*' };
	stack<char> op;
	stack<int> num;

	
	do {
		for (int i = 0; i < expression.length(); i++) {
			if (expression[i] == '+') {
				//
			}
			else if (expression[i] == '-') {

			}
			else if (expression[i] == '*') {

			}
		}


	} while (next_permutation(operations.begin(), operations.end()));











	return answer;
}