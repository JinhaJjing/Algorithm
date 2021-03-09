//https://www.acmicpc.net/problem/1904
//DP

#include <iostream>
using namespace std;
#define MAX 1000000 + 1

long long d[MAX];

int main() {
	int N;
	cin >> N;

	d[0] = 0;
	d[1] = 1;
	d[2] = 2;

	for (int i = 3; i <= N; i++) {
		d[i] = (d[i - 1] + d[i - 2]) % 15746;
	}

	cout << d[N] << "\n";
}