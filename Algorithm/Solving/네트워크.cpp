// https://programmers.co.kr/learn/courses/30/lessons/43162
// DFS

#include <string>
#include <vector>

using namespace std;

bool visit[200];

void dfs(int start, vector<vector<int>> &computers, int n) {
	//방문 check
	visit[start] = 1;
	for (int i = 0; i < n; i++)
	{
		if (!visit[i] && computers[start][i])//방문하지 않았고 연결되어있음
			dfs(i, computers, n);
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	for (int i = 0; i < n; i++)
	{
		if (!visit[i])//방문안했다면
		{
			answer++;
			dfs(i, computers, n);
		}
	}
	return answer;
}

int main() {
	solution(3, { {1,1,0},{1,1,1},{0,1,1} });
}