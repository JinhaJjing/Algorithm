//https://www.acmicpc.net/problem/1463
//DP

#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;

	int arr[12] = { 0, };
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;

	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		for (int i = 4; i <= n; i++)
			arr[i] = arr[i - 3] + arr[i - 2] + arr[i - 1];
		cout << arr[n] << "\n";
	}

	return 0;
}