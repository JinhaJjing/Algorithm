// https://programmers.co.kr/learn/courses/30/lessons/42748
// 정렬

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	vector<int> subarray;
	for (int i = 0; i < commands.size(); i++) {
		int j = commands[i][0]-1;
		int k = commands[i][1];

		for (j; j < k; j++) {
			subarray.push_back(array[j]);
		}
		sort(subarray.begin(), subarray.end());
		answer.push_back(subarray[(commands[i][2]-1)]);

		subarray.clear();
	}

	return answer;
}