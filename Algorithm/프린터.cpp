// https://programmers.co.kr/learn/courses/30/lessons/42587
// 큐

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

	while (inputs.empty()) {
		int curidx = inputs.front().first;
		int curprior = inputs.front().second;

		// TODO


	}


	return answer;
}
//내가 요청한 문서의 인덱스는 바뀌기 때문에 인덱스를 변화하려고 하니까 넘 복잡