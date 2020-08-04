// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AW-hOY5KeEIDFAVg&categoryId=AW-hOY5KeEIDFAVg&categoryType=CODE

#include <cstdio>
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int solve(int len, string right, string input) {
	int rightSum = 0;

	for (int i = 0; i < len; i++)
	{
		if (right[i] == input[i])
			rightSum += 1;
	}

	return rightSum;
}

int main() {
	int TC, strLen;
	string strRightAns, strInputAns;

	cin >> TC;

	for (int i = 0; i < TC; i++) {
		cin >> strLen;
		cin >> strRightAns;
		cin >> strInputAns;

		int sum = solve(strLen, strRightAns, strInputAns);
		cout << "#" << i + 1 << ' ' << sum << '\n';
	}
	return 0;
}