#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//�� ��° �� ���ǵ� ��Ȯ�� ����ؾ�����
bool cmp(const pair<int, double> &a, const pair<int, double> &b)
{
	if (a.second != b.second) return a.second > b.second;
	else return a.first < b.first;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector<pair<int, double>> percentage;
	vector<int> successed(N); //vector�Ҵ� �ȵż� ���Ը��ϱ淡 �̸� �Ҵ���
	vector<int> challenging(N);
	sort(stages.begin(), stages.end());

	for (int i = 0; i < stages.size(); i++) {
		if (stages[i] <= N)
			challenging[stages[i]-1] += 1;
		for (int j = 0; j < stages[i]-1; j++)
			successed[j] += 1;
	}

	for (int i = 0; i < N; i++) {
		if (challenging[i] == 0)
			percentage.push_back(make_pair(i+1, 0));
		else
			percentage.push_back(make_pair(i+1, (double)challenging[i] / (successed[i]+challenging[i])));
	}

	sort(percentage.begin(), percentage.end(), cmp);

	for (int i = 0; i < N; i++)
		answer.push_back(percentage[i].first);

	return answer;
}

int main() {
	int N = 5;
	vector<int> stages;
	stages = { 2, 1, 2, 6, 2, 4, 3, 3 };
	solution(N, stages);
}