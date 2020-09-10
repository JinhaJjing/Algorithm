// https://www.acmicpc.net/problem/1168
// ±¸Çö

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;
	vector<int> v;

	for (int i = 1; i <= N; i++)
		v.push_back(i);

	int idx = 0;

	cout << "<";
	while (v.size() > 1) {
		idx += K-1;
		if (idx >= v.size()) idx = idx % v.size();
		cout << v[idx] << ", ";
		v.erase(v.begin()+idx);
	}
	cout << v.front()<<">";

	return 0;
}