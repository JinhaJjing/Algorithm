// https://programmers.co.kr/learn/courses/30/lessons/12980
// ±¸Çö

#include <iostream>
using namespace std;

int solution(int n)
{
	int ans = 0;

	while (n != 0) {
		if (n % 2 == 0) {
			n = n / 2;
		}
		else {
			n -= 1;
			ans++;
		}
	}

	return ans;
}