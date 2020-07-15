#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue<int, vector<int>, greater<int>> pq; //max heap

	for (int food : scoville)
		pq.push(food);

	while (!pq.empty()) {
		if ((pq.top()>=K)) { //모든 것이 K보다 크면
			answer = scoville.size() - pq.size();
			return answer;
		}
		else {
			if (pq.size() >= 2) {
				int least = pq.top();
				pq.pop();
				int second_least = pq.top();
				pq.pop();

				int new_scoville = least + (second_least * 2);
				pq.push(new_scoville);
			}
			else return -1;
		}
	}
}