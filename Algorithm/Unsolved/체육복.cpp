// https://programmers.co.kr/learn/courses/30/lessons/42862
// category is greedy

#include <string>
#include <vector>

// 못찾겠다 꾀꼬리. 질문함.

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	vector<int> clothes;

	for (int i=0;i<n;i++)
		clothes.push_back(1);
	for (int i = 0; i < lost.size(); i++)
		clothes[lost[i] - 1]--;
	for (int i = 0; i < reserve.size(); i++)
		clothes[reserve[i] - 1]++;

	for (int i = 0; i < n; i++) {
		if (clothes[i] == 0) {
			if (i - 1 >= 0){
				if (clothes[i - 1] == 2) {
					clothes[i - 1]--;
					clothes[i]++;
				}
			}
			else if (i + 1 <= n - 1){
				if (clothes[i + 1] == 2) {
					clothes[i + 1]--;
					clothes[i]++;
				}
			}
		}
	}

	for (int c : clothes)
		if (c >= 1) answer++;

	return answer;
}

int main() {
	//solution(5, { 2,4 }, { 1,3,5 });
	//solution(5, { 2,4 }, { 3 });
	//solution(3, { 3 }, { 1 });
	//solution(3, { 1,3 }, { 1,2 });
	//solution(8, { 5,6 }, { 4,5 });
	//solution(3, { 2,3 }, { 1 });//2
	//solution(5, { 3,4 }, { 4,5 });//4
	//solution(18, { 7,8,11,12 }, { 1,6,8,10 });//17
	//solution(24, { 12,13,16,17,19,20,21,22 }, { 1,22,16,18,9,10});//19
	//solution(7, { 2,3,4 }, { 1,2,3,6 });
	//solution(5, { 2,3,4 }, { 3,4,5 });
	//solution(10, { 3,9,10 }, { 3,8,9 });
}