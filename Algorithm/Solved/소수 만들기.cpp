// https://programmers.co.kr/learn/courses/30/lessons/12977
// 단순 구현

#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int num) {
	for (int i = 2; i <= sqrt(num); i++)
		if (num % i == 0)	return false;
	return true;
}

int solution(vector<int> nums) {
	int answer = 0;

	for (int i = 0; i < nums.size(); i++) {
		for (int j = i + 1; j < nums.size(); j++) {
			for (int k = j + 1; k < nums.size(); k++) {
				int temp = nums[i] + nums[j] + nums[k];
				if (isPrime(temp)) answer++;
			}
		}
	}
	return answer;
}