// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AW9j74FacD0DFAUY9280
// 큐

#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;

int main() {
	int TC;
	cin >> TC;
	for (int t = 0; t < TC; t++) {
		int n, m;
		cin >> n >> m;

		int* R = new int[n];
		int* W = new int[m];
		for (int i = 0; i < n; i++) {
			cin >> R[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> W[i];
		}

		queue<int> enterQueue;
		for (int i = 0; i < 2*m; i++) {
			int carNum;
			cin >> carNum;
			enterQueue.push(carNum);
		}

		int income = 0;
		queue<int> waitQueue;
		int* parkingLot = new int[n]();
		while (!enterQueue.empty()) {
			int car;
			car=enterQueue.front();
			enterQueue.pop();
			bool parked = false;

			if (car > 0) { // 들어가려는 차
				for (int i = 0; i < n; i++) {
					if (parkingLot[i] == 0) { // 주차장 비어있으면 
						if (!waitQueue.empty()) { // 기다리던 차 있으면 그거 먼저 주차
							parkingLot[i] = waitQueue.front();
							waitQueue.pop();
							income += R[i] * W[parkingLot[i] - 1];
						}
						else {
							parkingLot[i] = car; // 주차
							income += R[i] * W[parkingLot[i] - 1];
						}
						parked = true;
						break;
					}
				}
				if (!parked)
					waitQueue.push(car); // 대기열에 추가
			}
			else { // 나오려는 차
				for (int i = 0; i < n; i++) {
					if (parkingLot[i] == (-1) * car) { // 출차
						parkingLot[i] = 0;
						if (!waitQueue.empty()) { // 빈 주차공간에 곧바로 주차
							parkingLot[i] = waitQueue.front();
							waitQueue.pop();
							income += R[i] * W[parkingLot[i] - 1];
						}
						break;
					}
				}
			}
		}

		cout << "#" << t + 1 << ' ' << income << '\n';

		delete[] R, W;
	}
	return 0;
}