// https://programmers.co.kr/learn/courses/30/lessons/12979
// ����

#include <iostream>
#include <vector>

using namespace std;

//���ӵ� ĭ �� üũ...�� �ƴѰ�?
//��ĭ�� ������������ ��ϳ� �;��µ�
//�ƴϾ���. �׷� ��찡 ����������.
//���޾ȵǴ� ĭ�� ���� ��~

int solution(int n, vector<int> stations, int w)
{
	int answer = 0;

	int start = 0;
	for (int i = 0; i < stations.size(); i++) {
		int l = stations[i] - w - 1;
		int len = l - start;
		start = stations[i] + w; //5���� - ���� ���ؼ�

		if (len > 0) {
			answer += len / (2 * w + 1);
			if ((len % (2 * w + 1)) != 0)
				answer += 1;
		}
	}

	int len = n - stations[stations.size() -1] - w;
	if (len > 0) {
		answer += len / (2 * w + 1);
		if ((len % (2 * w + 1)) != 0)
			answer += 1;
	}

	return answer;
}

int main() {
	//solution(11, { 4, 11 }, 1);
	solution(16, { 9 }, 2);
}