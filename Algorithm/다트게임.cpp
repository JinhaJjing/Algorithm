// https://programmers.co.kr/learn/courses/30/lessons/17682
// 문자열

#include <string>
#include <vector>

using namespace std;

int solution(string dartResult) {
	int answer = 0;
	vector <int> scores;

	for (int i = 0; i < dartResult.length(); i++) {
		int scize = scores.size();
		if (dartResult[i] == 'S') continue;
		else if (dartResult[i] == 'D') {
			scores[scize - 1] *= scores[scize - 1];
		}
		else if (dartResult[i] == 'T') {
			scores[scize - 1] *= (scores[scize - 1] * scores[scize - 1]);
		}
		else if (dartResult[i] == '*') {
			scores[scize - 1] *= 2;
			if (scize > 1)
				scores[scize - 2] *= 2;
		}
		else if (dartResult[i] == '#') {
			scores[scize - 1] *= (-1);
		}
		else { //점수
			if (dartResult[i + 1] == '0') { //숫자가 나왔는데 또 숫자니까 10을 의미
				scores.push_back(10);
				i++; //두자리를 봤으므로
			}
			else
				scores.push_back(dartResult[i]-'0');
		}
	}

	for (int i : scores)
		answer += i;

	return answer;
}

int main() {
	solution("1S2D*3T");
	solution("1D2S#10S");
	solution("1D2S0T");
	solution("1S*2T*3S");
	solution("1D#2S*3S");
	solution("1T2D3D#");
	solution("1D2S3T*");
}