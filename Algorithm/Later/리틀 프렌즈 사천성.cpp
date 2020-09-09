// https://programmers.co.kr/learn/courses/30/lessons/1836
// 2017카카오코드 본선

#include <string>
#include <vector>
#include <queue>

using namespace std;

//갈 수 있는 경로가 존재하는지 확인하는 방법은 참고하였고 이는 아래와 같다.
//출발 블록에서 상하좌우로 막힘없이 갈 수 있는 곳까지의 모든 블록들의 위치를 담은 집합을 구한다.
//도착 블록에서도 마찬가지로 집합을 구한다.
//여집합이 존재한다면 경로는 존재한다.

int dx[4] = { -1,1,0,0 };//상 하 좌 우
int dy[4] = { 0,0,-1,1 };

struct Node { int x; int y; };
vector<vector<int>> visited(101, vector<int>(101, 0)); // 할당 및 초기화

void search(Node node) {
    queue<Node> accessqueue;

    visited[node.x][node.y] = true; // (방문한 노드 체크)
    accessqueue.push(node); // 1-1. 큐의 끝에 추가

    // 3. 큐가 소진될 때까지 계속한다.
    while (!accessqueue.empty()) {
        Node r = accessqueue.front(); // 큐의 앞에서 노드 추출
        accessqueue.pop();
        visited[r.x][r.y] = true; // 2-1. 큐에서 추출한 노드 방문
        // 2-2. 큐에서 꺼낸 노드와 인접한 노드들을 모두 차례로 방문한다.
        for (int i = 0; i < 4; i++) {
            int nx = r.x + dx[i];
            int ny = r.y + dy[i];
            if (visited[nx][ny] == 0) {// (방문한 노드 체크)
                visited[nx][ny] = 1;
                Node n = { nx,ny };
                accessqueue.push(n);// 2-3. 큐의 끝에 추가
            }
        }
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(int m, int n, vector<string> board) {
    string answer = "";

    Node root;
    root.x = 0;
    root.y = 0;
    search(root);






    return answer;
}