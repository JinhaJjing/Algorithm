#include <string>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	stack<int> prgStack;

	for (int i = progresses.size()-1; i >=0; i--)
		prgStack.push(ceil((double)(100 - progresses[i]) / speeds[i]));

	while(!prgStack.empty()) {//스택의 크기가 변해,,
		int top = prgStack.top();
		prgStack.pop();
		int funcNum = 1;
		while (!prgStack.empty()){
			int temp = prgStack.top();
			if (top > temp) {
				prgStack.pop();
				funcNum++;
			}
			else break;
		}
		answer.push_back(funcNum);
	}
	return answer;
}

int main() {
	vector<int> progresses;
	vector<int> speeds;

	progresses = { 93, 30, 55 };
	speeds = { 1,30,5 };

	solution(progresses, speeds);
}