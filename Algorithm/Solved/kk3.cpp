#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

struct Data {
	string language;
	string job;
	string career;
	string soulfood;
	int score;
};

bool cmp(Data& a, Data& b) {
	return a.score > b.score;
}

vector<string> tokenize_getline(const string& data, const char delimiter = ' ') {
	vector<string> result;
	string token;
	stringstream ss(data);

	while (getline(ss, token, delimiter)) {
		result.push_back(token);
	}
	return result;
}

vector<int> solution(vector<string> info, vector<string> query) {
	vector<int> answer;

	vector<Data> occupants;

	for (int i = 0; i < info.size(); i++) {
		string s = info[i];
		vector<string> t = tokenize_getline(s, ' ');

		Data p = { t[0],t[1],t[2],t[3],stoi(t[4]) };
		occupants.push_back(p);
	}
	sort(occupants.begin(), occupants.end(), cmp);

	for (int i = 0; i < query.size(); i++) {
		int cnt = 0;
		string s = query[i];
		vector<string> t = tokenize_getline(s, ' ');

		for (int j = 0; j < occupants.size(); j++) {
			Data o = occupants[j];
			string language = t[0];
			string job = t[2];
			string career = t[4];
			string soulfood = t[6];
			int score = stoi(t[7]);

			if (o.score < score) break;

			if (language == "-") language = o.language;
			if (job == "-") job = o.job;
			if (career == "-") career = o.career;
			if (soulfood == "-") soulfood = o.soulfood;

			if (o.language == language && o.job == job && o.career == career && o.soulfood == soulfood)
				cnt++;
		}
		answer.push_back(cnt);
	}

	return answer;
}

int main() {
	solution({ "java backend junior pizza 150", "python frontend senior chicken 210", "python frontend senior chicken 150", "cpp backend senior pizza 260", "java backend junior chicken 80", "python backend senior chicken 50" },
		{ "java and backend and junior and pizza 100", "python and frontend and senior and chicken 200", "cpp and - and senior and pizza 250", "- and backend and senior and - 150", "- and - and - and chicken 100", "- and - and - and - 150" });
}