// https://programmers.co.kr/learn/courses/30/lessons/42587
// (우선순위)큐

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	priority_queue<int> pq;
	queue<pair<int, int>> inputs; // index, priority
	
	for ( int i=0;i<priorities.size();i++){
		int p = priorities[i];
		pq.push(p);
		inputs.push(make_pair(i, p));
	}

	while (!inputs.empty()) {
		int curidx = inputs.front().first;
		int curprior = inputs.front().second;

		// 가장 중요한 프린터
		if (curprior == pq.top()) {
			answer++;
			pq.pop();
			inputs.pop();
			if (curidx == location)
				break;
		}
		else {
			inputs.pop();
			inputs.push(make_pair(curidx, curprior));
		}
	}

	return answer;
}
//첨에 생각한 방식은 요청한 문서의 인덱스는 바뀌기 때문에 인덱스를 변화하려고 하니까 넘 복잡

int main() {
	solution({ 2,1,3,2 }, 2);
	solution({ 1,1,9,1,1 }, 0);
}