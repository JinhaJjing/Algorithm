// https://programmers.co.kr/learn/courses/30/lessons/42746
// 정렬

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//길이 비교해서 짧은거 우선
//같다면 모든 인덱스 비교해서 큰 거 나오면 바로 리턴

//하지만 34, 3 => 343>334 경우
//짧은 3 우선이 아니라 34 우선. 4가 3보다 크기 때문
//해결방법이....다른사람 풀이 마일리지 내고 봤는디,,
//343,334만들어서 둘의 크기 비교하는 방식이면 쉽게 풀리는데
//그거 아니면 많이 지저분해짐

bool cmp(int& a,int& b) {
	string sa = to_string(a);
	string sb = to_string(b);
	if (sa.length() > sb.length()) return false;
	else if (sa.length() < sb.length()) return true;
	else {
		for (int i = 0; i < sa.length(); i++) {
			int na= to_string(a).at(i) - '0';
			int nb= to_string(b).at(i) - '0';
			if (na > nb) return true;
			else if (na < nb) return false;
			else continue;
		}
	}
}

string solution(vector<int> numbers) {
	string answer = "";
	sort(numbers.begin(), numbers.end(), cmp);
	for (int i : numbers) answer += to_string(i);
	return answer;
}

int main() {
	solution({ 6,10,2 });
}