//https://www.acmicpc.net/problem/1699
//DP

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100000 + 1

long long d[MAX];

int main() {
	int N;
	cin >> N;

	for (int i = 0; i <= N; i++) {
		d[i] = i;
		for (int j = 1; (j * j) <= i; j++) {
			d[i] = min(d[i], d[i - j * j] + 1);
		}
	}
	cout << d[N] << "\n";
}