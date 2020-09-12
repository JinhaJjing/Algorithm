#include <string>
#include <vector>

using namespace std;

//1시간

string solution(string new_id) {
	//1
	for (int i = 0; i < new_id.length(); i++) {
		if (new_id[i] >= 65 && new_id[i] <= 90)
			new_id[i] = tolower(new_id[i]);
	}
	//2
	for (int i = 0; i < new_id.length(); i++) {
		if ((new_id[i] >= 97 && new_id[i] <= 122) || (new_id[i] >= 48 && new_id[i] <= 57) || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
			continue;
		else {
			new_id.erase(i, 1);
			i -= 1; //나중에 인덱스땜에 터질수도.
		}
	}
	//3
	for (int i = 0; i < new_id.length(); i++) {
		if (new_id[i] == '.') {
			for (int j = i + 1; j < new_id.length(); j++) {
				if (new_id[j] != '.') break;
				else {
					new_id.erase(j, 1);
					j -= 1; //나중에 인덱스땜에 터질수도.
				}
			}
		}
	}
	//4
	if (!new_id.empty())
		if (new_id[0] == '.') new_id.erase(0, 1);
	if(!new_id.empty())
		if (new_id[new_id.length() - 1] == '.') new_id.pop_back();
	//5
	if (new_id.length() == 0) new_id.push_back('a');
	else if (new_id.length() >= 16) {//6
		new_id = new_id.substr(0, 15);
		if (new_id[new_id.length() - 1] == '.') new_id.pop_back();
	}
	//7
	if (new_id.length() <= 2) {
		new_id.push_back(new_id[new_id.length() - 1]);
		new_id.push_back(new_id[new_id.length() - 1]);
		new_id = new_id.substr(0, 3);
	}

	return new_id;
}

int main() {
	//solution("...!@BaT#*..y.abcdefghijklm.");
	//solution("z-+.^.");
	//solution("=.=");
	solution("123_.def");
	solution("abcdefghijklmn.p");
}