// https://www.acmicpc.net/problem/6588
// �Ҽ�

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> arr(1000001);
vector<int> prime;

// �����佺�׳׽��� ü
void setChe1() {
    arr[0] = arr[1] = -1;
    for (int i = 2; i < 1000001; i++)
        arr[i] = i;

    for (int i = 2; i * i < 1000001; i++)
        if (arr[i] == i)
            for (int j = i * i; j < 1000001; j += i)
                if (arr[j] == j)
                    arr[j] = i;

    //Ȧ���� �Ҽ��� ����
    for (int i = 3; i < 1000001; i++)
        if (arr[i] == i)
            prime.push_back(i);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    setChe1();

    while (1) {
        int n;
        cin >> n;
        if (n == 0) break;
        for (int i = 0; i < prime.size(); i++){
            if (arr[n - prime[i]] == n - prime[i])
            {
                cout << n << " = " << prime[i] << " + " << n - prime[i] << "\n";
                break;
            }
        }
    }
    return 0;
}