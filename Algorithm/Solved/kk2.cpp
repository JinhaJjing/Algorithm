#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> result;

    set<char> everymenu;
    vector<char> menus;

    for (int i = 0; i < orders.size(); i++) {
        for (int j = 0; j < orders[i].size(); j++)
            everymenu.insert(orders[i][j]);
    }
    for (char c : everymenu)
        menus.push_back(c);


    vector<int> menuCnt;
    for (int i = 0; i < course.size(); i++) {
        for (int j = 0; j < course[i]; j++)
            menuCnt.push_back(1);
        while (menuCnt.size() < menus.size())
            menuCnt.push_back(0);

        sort(menuCnt.begin(), menuCnt.end());

        int maxOrder = 0;

        do {
            vector<char> v;
            for (int i = 0; i < menus.size(); i++)
                if (menuCnt[i] == 1) v.push_back(menus[i]);

            int hit = 0;
            for (int i = 0; i < orders.size(); i++) {
                int cnt = 0;
                for (int j = 0; j < orders[i].size(); j++) {//A,B,C,F,G
                    for (int k = 0; k < v.size(); k++) {//AB
                        if (v[k] == orders[i][j]) {//A A, B B
                            cnt++;
                            break;
                        }
                    }
                    if (cnt == v.size()) {
                        hit += 1;
                        break;
                    }
                }
            }

            if (hit >= 2) {
                string s;
                for (int i = 0; i < v.size(); i++)
                    s += v[i];
                if (maxOrder < hit) {
                    maxOrder = hit;
                    for (int l = 0; l < result.size(); l++) { //이미 들어있던 낮은 횟수들 지움
                        if (result[l].length() == s.length()) {
                            result.erase(result.begin() + l);
                            l -= 1;
                        }
                    }
                    if (!result.empty()) {
                        if (result[result.size() - 1].length() >= s.length())
                            result.pop_back();
                    }
                    result.push_back(s);
                }
                else if (maxOrder == hit) { // 항상 같은 course일 수 밖에 없음
                    if (result[result.size() - 1].length() == s.length())
                        result.push_back(s);
                }
            }

        } while (next_permutation(menuCnt.begin(), menuCnt.end()));

        menuCnt.clear();
    }

    sort(result.begin(), result.end());
    return result;
}

int main() {
    //solution({ "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" }, { 2,3,4 });
    solution({ "ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD" }, { 2,3,5 });
    solution({ "XYZ", "XWY", "WXA" }, { 2,3,4 });
}