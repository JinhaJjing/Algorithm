#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
	int answer = 0;
	set<int> type;

	for (int i : nums)
		type.insert(i);

	answer = nums.size() / 2 >= type.size() ? type.size() : nums.size()/2;

	return answer;
}//�̰� �� lv2�ΰ�..?