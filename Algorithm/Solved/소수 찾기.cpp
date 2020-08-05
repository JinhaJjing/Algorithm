// https://programmers.co.kr/learn/courses/30/lessons/42839
// 완전탐색

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

//모든 조합 고려
//소수 계산
//소수만 개수추가

bool isprime(int num) {
	for (int i = 2; i <= sqrt(num); i++)
		if (num % i == 0)	return false;
	return true;
}

int solution(string numbers) {
	int answer = 0;
	map<int, int> m;
	
	sort(numbers.begin(), numbers.end(), greater<int>());

	for (int i = 2; i <= stoi(numbers); i++) {
		for (int k = 0; k < numbers.size(); k++) {
			m[numbers[k] - '0']++;//개수세서넣기
		}
		if (isprime(i)) {
			bool prime = true;
			for (int j = 0; j < to_string(i).length(); j++) {
				//map에 있고 0보다 크면 --
				if (m[to_string(i)[j] - '0'] > 0)	m[to_string(i)[j] - '0']--;
				else {
					prime = false;
					break;
				}
			}
			if(prime)	answer++;
		}
		for (int l = 0; l < numbers.size(); l++) {
			m[numbers[l] - '0'] = 0;//초기화
		}
	}

	return answer;
}

int main() {
	solution("17");
	solution("011");
}