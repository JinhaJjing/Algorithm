// https://programmers.co.kr/learn/courses/30/lessons/62048
// ����ã��

using namespace std;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

long long solution(int w, int h) {
	long long sum = (long long)w * (long long)h;

	if (w < h) {
		long long tmp = w;
		w = h;
		h = tmp;
	}
	int a = gcd(w, h);

	//�� ��� �ȿ����� (����� ���� ũ�� + ����� ���� ũ�� - 1) ����ŭ�� �簢�� ���� ���� ��������.
	return (long long)w * (long long)h - a * (w / a + h / a - 1);
}