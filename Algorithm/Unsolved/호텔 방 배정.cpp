// https://programmers.co.kr/learn/courses/30/lessons/64063
// ȿ���� �׽�Ʈ �����

#include <string>
#include <vector>

using namespace std;

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;

    vector<long long> rooms(k,0);

    for (int i = 0; i < room_number.size(); i++) {
        int wish_room = room_number[i];
        if (rooms[wish_room] == 0) { //�� ��
            rooms[wish_room] = 1;
            answer.push_back(wish_room);
        }
        else { //������ ��
            for (int j = wish_room + 1; j <= k; j++) {
                if (rooms[j] == 0) {
                    rooms[j] = 1;
                    answer.push_back(j);
                    break;
                }
            }
        }
    }

    return answer;
}