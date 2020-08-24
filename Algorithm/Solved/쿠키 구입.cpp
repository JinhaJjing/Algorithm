// https://programmers.co.kr/learn/courses/30/lessons/49995
// time complexity

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> cookie) {
	int answer = 0;
	int sum[2001] = { 0, };

	for (int i = 0; i < cookie.size(); ++i)
		sum[i + 1] = sum[i] + cookie[i];

	for (int m = 1; m < cookie.size(); m++) {
		for (int r = m + 1; r <= cookie.size(); r++) {
			int son2 = sum[r] - sum[m];
			if (answer >= son2 || son2 > sum[m]) continue;

			for (int l = 0; l < m; l++) {
				int son1 = sum[m]-sum[l];
				if (son1 == son2) {
					if(answer<son1)	answer = son1;
					break;
				}
			}
		}
	}

	return answer;
}

int main() {
	solution({ 1,1,2,3 });
}