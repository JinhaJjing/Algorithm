#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, x1, y1, r1, x2, y2, r2;
	cin >> N;
	for (int n = 0; n < N; n++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		int xd = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
		int rd1 = (r1 - r2) * (r1 - r2); //최단거리
		int rd2 = (r1 + r2) * (r1 + r2); //최장거리

		if (xd == 0) {
			if (rd1 == 0) cout << -1 << endl;  //같은 원인 경우
			else cout << 0 << endl; //원의 크기만 다른 경우
		}
		else if (rd1 < xd && xd < rd2) cout << 2 << endl; //약간 겹치는 경우 
		else if (xd == rd1 || xd == rd2) cout << 1 << endl;//내접 또는 외접인 경우
		else cout << 0 << endl;//멀리 떨어진 경우
	}
}