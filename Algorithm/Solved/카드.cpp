// https://www.acmicpc.net/problem/11652
// sorting based on several measures

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(pair<long long, int>& a, pair<long long, int>& b) {
	if (a.second != b.second) return a.second > b.second;
	else return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	map<long long, int> m;

	cin >> N;
	for (int n = 0; n < N; n++) {
		long long card;
		cin >> card;
		m[card] += 1;
	}

	vector<pair<long long,int>> v(m.size());
	copy(m.begin(), m.end(), v.begin());

	sort(v.begin(), v.end(), cmp);
	cout << v[0].first;
}