#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> ans;

    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i+1; j < numbers.size(); j++) {
            int res = numbers[i] + numbers[j];
            ans.insert(res);
        }
    }

    for (int i:ans)
        answer.push_back(i);

    sort(answer.begin(), answer.end());
    return answer;
}