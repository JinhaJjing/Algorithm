// https://programmers.co.kr/learn/courses/30/lessons/62048
// 패턴찾기

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

	//한 블록 안에서는 (블록의 가로 크기 + 블록의 세로 크기 - 1) 수만큼의 사각형 위로 선이 지나간다.
	return (long long)w * (long long)h - a * (w / a + h / a - 1);
}