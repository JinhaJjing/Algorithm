// https://programmers.co.kr/learn/courses/30/lessons/1836
// 2017īī���ڵ� ����

#include <string>
#include <vector>
#include <queue>

using namespace std;

//�� �� �ִ� ��ΰ� �����ϴ��� Ȯ���ϴ� ����� �����Ͽ��� �̴� �Ʒ��� ����.
//��� ��Ͽ��� �����¿�� �������� �� �� �ִ� �������� ��� ��ϵ��� ��ġ�� ���� ������ ���Ѵ�.
//���� ��Ͽ����� ���������� ������ ���Ѵ�.
//�������� �����Ѵٸ� ��δ� �����Ѵ�.

int dx[4] = { -1,1,0,0 };//�� �� �� ��
int dy[4] = { 0,0,-1,1 };

struct Node { int x; int y; };
vector<vector<int>> visited(101, vector<int>(101, 0)); // �Ҵ� �� �ʱ�ȭ

void search(Node node) {
    queue<Node> accessqueue;

    visited[node.x][node.y] = true; // (�湮�� ��� üũ)
    accessqueue.push(node); // 1-1. ť�� ���� �߰�

    // 3. ť�� ������ ������ ����Ѵ�.
    while (!accessqueue.empty()) {
        Node r = accessqueue.front(); // ť�� �տ��� ��� ����
        accessqueue.pop();
        visited[r.x][r.y] = true; // 2-1. ť���� ������ ��� �湮
        // 2-2. ť���� ���� ���� ������ ������ ��� ���ʷ� �湮�Ѵ�.
        for (int i = 0; i < 4; i++) {
            int nx = r.x + dx[i];
            int ny = r.y + dy[i];
            if (visited[nx][ny] == 0) {// (�湮�� ��� üũ)
                visited[nx][ny] = 1;
                Node n = { nx,ny };
                accessqueue.push(n);// 2-3. ť�� ���� �߰�
            }
        }
    }
}

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
string solution(int m, int n, vector<string> board) {
    string answer = "";

    Node root;
    root.x = 0;
    root.y = 0;
    search(root);






    return answer;
}