//https://programmers.co.kr/learn/courses/30/lessons/68645?language=cpp

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
	vector<vector<int>> arr(n + 1, vector<int>(n + 1));

	int state = 0;
	int x = 0, y = 0, num = 1;
	for (int i = 0; i < n; i++) {
		if (state == 0)
		{
			for (int j = i; j < n; j++) arr[x++][y] = num++;
			x--;
			y++;
			state = 1;
		}
		else if (state == 1)
		{
			for (int j = i; j < n; j++) arr[x][y++] = num++;
			x--;
			y -= 2;
			state = 2;
		}
		else if (state == 2)
		{
			for (int j = i; j < n; j++) arr[x--][y--] = num++;
			x += 2;
			y++;
			state = 0;
		}
	}

	vector<int> answer;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			answer.push_back(arr[i][j]);
		}
	}

	return answer;
}