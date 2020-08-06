// https://programmers.co.kr/learn/courses/30/lessons/42583
// 큐

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	int curweight = 0;
	int crossed_trucks = 0;
	queue<pair<int, int>> crossing;//idx, weight
	queue<int> waiting;

	for (int t : truck_weights)
		waiting.push(t);

	while (crossed_trucks!=truck_weights.size()) {
		//시간이 흐르므로 차가 다리에서 전진
		int csize = crossing.size();
		for (int i = 0; i < csize; i++) {
			pair<int, int> c = crossing.front();
			crossing.pop();
			c.first -= 1;
			if (c.first >= 0) crossing.push(c);
			else {
				curweight -= c.second;
				crossed_trucks += 1;
			}
		}

		//진입, 출차 관리
		csize = crossing.size();
		if (curweight < weight&&csize < bridge_length) { // 다리의 무게, 길이를 만족하고
			if (csize == 0) {
				if (curweight + waiting.front() <= weight) {// 진입해도 되는 무게인 경우
					crossing.push(make_pair(bridge_length - 1, waiting.front()));
					curweight += waiting.front();
					waiting.pop();
				}
			}
			else {
				if (crossing.back().first < bridge_length - 1) {// 진입할 공간이 있고
					if (waiting.size() > 0) {
						if (curweight + waiting.front() <= weight) {// 진입해도 되는 무게인 경우
							//다리 시작점에 차 진입
							crossing.push(make_pair(bridge_length - 1, waiting.front()));
							curweight += waiting.front();
							waiting.pop();
						}
					}
				}
			}
		}
		answer++;

	}

	return answer;
}