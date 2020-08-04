// https://programmers.co.kr/learn/courses/30/lessons/42840
// 완전탐색

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
	int student1[5] = { 1,2,3,4,5 };
	int student2[8] = { 2,1,2,3,2,4,2,5 };
	int student3[10] = { 3,3,1,1,2,2,4,4,5,5 };

	vector<int> answer;
	int max_score = 0;
	int score[3] = { 0, };

	for (int i = 0; i < answers.size(); i++) {
		if (answers[i] == student1[i % 5])
			score[0] += 1;
		if (answers[i] == student2[i % 8])
			score[1] += 1;
		if (answers[i] == student3[i % 10])
			score[2] += 1;
	}

	//크기비교
	max_score = max(max(score[0], score[1]), score[2]);
	for (int i = 0; i < 3; i++)
		if (max_score == score[i])
			answer.push_back(i + 1);

	return answer;
}