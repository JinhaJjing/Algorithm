// https://programmers.co.kr/learn/courses/30/lessons/17686
// 문자열, 구현
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<pair<string, string>, string> &a, const pair<pair<string, string>, string> &b)
{
	//대문자화
	string ahead = a.first.first;
	string bhead = b.first.first;
	for (int i = 0; i < ahead.size(); i++) {
		if (ahead[i] >= 'a'&&ahead[i] <= 'z')
			ahead[i] = toupper(ahead[i]);
	}
	for (int i = 0; i < bhead.size(); i++) {
		if (bhead[i] >= 'a'&&bhead[i] <= 'z')
			bhead[i] = toupper(bhead[i]);
	}

	if (ahead==bhead)
		return stoi(a.first.second) < stoi(b.first.second); //number 순
	else return ahead < bhead; //head 순
}

vector<string> solution(vector<string> files) {
	vector<string> answer;
	vector<int> number = { 0,1,2,3,4,5,6,7,8,9 };
	vector <pair<pair<string, string>,string>> file;

	// 파일명 parsing
	for (int i = 0; i < files.size(); i++ ) {
		for (int j = 0; j < files[i].size(); j++) {
			if (files[i][j] - '0' >= 0 && files[i][j] - '0' <= 9) { // 숫자발견
				string head, number, tail;
				head = files[i].substr(0, j);
				number = files[i].substr(j, 1);
				for (int k = j + 1; k < files[i].size(); k++) {
					if (files[i][k] - '0' >= 0 && files[i][k] - '0' <= 9)
						number += files[i][k];
					else {
						tail = files[i].substr(k, files[i].size());
						break;
					}
				}
				file.push_back(make_pair(make_pair(head, number),tail));
				break;
			}
		}
	}

	// 파일명 sort
	stable_sort(file.begin(), file.end(), compare);
	
	for (int i = 0; i < files.size(); i++)
		answer.push_back(file[i].first.first + file[i].first.second + file[i].second);

	return answer;
}

int main() {
	//solution({"img001.png","ims0002.png","img02.png","img1.png","IMG01.GIF","img2.JPG"});
	//solution({"img12.png","img10.png","img02.png","img1.png","IMG01.GIF","img2.JPG"});
	//solution({"F-5 Freedom Fighter","B-50 Superfortress","A-10 Thunderbolt II","F-14 Tomcat"});
	solution({"F-5","B-50 Superfortress","A-10 Thunderbolt II","F-14 Tomcat"});
}
// 구조체 쓰면 더 깔끔쓰하고 편한데..
// 구현은 쉬우나 sort에서 비교하는 값이 동일한 경우에는 바꾸지 않는 안정된 stable_sort를 사용해야했음