// 문자열

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int answer = 0;
	string oristr, schstr;
	cin >> oristr >> schstr;

	while (1) {
		if (oristr.length() == 0) return answer;
		size_t nstart=oristr.find(schstr);
		if (nstart >= 0 && nstart <= oristr.length()) {
			answer++;
			oristr = oristr.substr(nstart + schstr.length());
		}
		else return answer;
	}
}