// https://programmers.co.kr/learn/courses/30/lessons/1844
// bfs

#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int> > maps)
{
	int answer = 0;
	queue<pair<pair<int, int>, int>> bqueue;
	vector<vector<int>> visited(100, vector<int>(100, 0));
	int dx[4] = { -1,1,0,0 };//상하좌우
	int dy[4] = { 0,0,-1,1 };
	int n = maps.size();
	int m = maps[0].size();
	int cnt = 1;

	visited[0][0] = true;
	bqueue.push(make_pair(make_pair(0, 0), cnt));

	while (!bqueue.empty()) {
		int x = bqueue.front().first.first;
		int y = bqueue.front().first.second;
		cnt = bqueue.front().second;
		bqueue.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (!(nx >= 0 && ny >= 00 && nx < n&&ny < m)) continue;

			if (!visited[nx][ny] && maps[nx][ny]) {
				bqueue.push(make_pair(make_pair(nx, ny), cnt + 1));
				visited[nx][ny] = true;
			}
		}

		if (x == n - 1 && y == m - 1) {
			return answer = cnt;
		}
	}

	return -1;
}

int main() {
	solution({ {1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1} });
	solution({ {1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,0},{0,0,0,0,1} });
}