// https://www.acmicpc.net/problem/11650
// sorting based on several measures

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
	if (a.first != b.first) return a.first < b.first;
	else return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<pair<int, int>> coor;
	int N;
	cin >> N;
	for (int n = 0; n < N; n++) {
		int x, y;
		cin >> x >> y;
		coor.push_back(make_pair(x, y));
	}

	sort(coor.begin(), coor.end(), cmp);

	for (int i = 0; i < coor.size(); i++) {
		cout << coor[i].first << " " << coor[i].second << "\n";
	}
}