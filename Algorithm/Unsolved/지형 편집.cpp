// https://programmers.co.kr/learn/courses/30/lessons/12984
// time complexity

#include<vector>

using namespace std;

// it seems to need mathematical approach

long long solution(vector<vector<int> > land, int P, int Q) {

    long long maxheight = 0;
    for (int i = 0; i < land.size(); i++) {
        for (int j = 0; j < land.size(); j++) {
            if (maxheight < land[i][j])
                maxheight = land[i][j];
        }
    }
    long long minheight = maxheight;
    for (int i = 0; i < land.size(); i++) {
        for (int j = 0; j < land.size(); j++) {
            if (minheight > land[i][j])
                minheight = land[i][j];
        }
    }

    long long answer = 100 * land.size() * land.size() * maxheight;

    for (int height = minheight; height <= maxheight; height++) {
        long long cost = 0;
        for (int i = 0; i < land.size(); i++) {
            for (int j = 0; j < land.size(); j++) {
                if (land[i][j] < height)
                    cost += P * (height - land[i][j]);
                else if (land[i][j] > height)
                    cost += Q * (land[i][j] - height);
            }
        }
        if (answer > cost) answer = cost;
    }

    return answer;
}