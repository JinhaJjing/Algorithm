// https://programmers.co.kr/learn/courses/30/lessons/43165
// dfs

#include <string>
#include <vector>

using namespace std;

void dfs(vector<int>& numbers, int& answer, int target, int count, int sum) {
	if (count == numbers.size() - 1) {
		if (target == sum + numbers[count])	answer++;
		if (target == sum - numbers[count]) answer++;
		return;
	}
	dfs(numbers, answer, target, count++, sum - numbers[count]);
	dfs(numbers, answer, target, count++, sum + numbers[count]);
}

int solution(vector<int> numbers, int target) {
	int answer = 0;
	dfs(numbers, answer, target, 0, 0);
	return answer;
}