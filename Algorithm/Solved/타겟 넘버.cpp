// https://programmers.co.kr/learn/courses/30/lessons/43165
// dfs

#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(vector<int> numbers, int target, int count, int sum) {
	if (count == numbers.size()) {
		if (sum == target)	answer++;
		return;
	}
	dfs(numbers, target, count+1, sum - numbers[count]);
	dfs(numbers, target, count+1, sum + numbers[count]);
	//count++로 했다가 계속 터져서 원인 찾느라 진짜...후(심한말)
}

int solution(vector<int> numbers, int target) {
	dfs(numbers, target, 0, 0);
	return answer;
}