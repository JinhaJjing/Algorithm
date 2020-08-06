// 

#include <string>
#include <vector>

// TODO : keep trying

using namespace std;

int solution(vector<string> ip_addrs, vector<string> langs, vector<int> scores) {
    int good_participants=0;

    vector<string>::iterator iter;
    vector<string> ip;

    for (int i = 0; i < langs.size(); i++) {
        iter= find(ip.begin(), ip.end(), ip_addrs[i]);
        if(iter==ip.end())
            ip.push_back(ip_addrs[i]);
    }

    int size = ip.size();
    int* count = new int[size]();
    for (int i = 0; i < langs.size(); i++) {
        for (int j = 0; j < ip.size(); j++) {
            if (ip[j].compare(ip_addrs[i]) == 0)//같다
                count[j] += 1;
        }
    }
    
    int student = ip_addrs.size();
    bool* students = new bool[student];
    string language = "0";

    for (int i = 0; i < ip.size(); i++) {
        if (count[i] >= 4) {
            for (int j = 0; j < ip_addrs.size(); j++) {
                if (ip[i].compare(ip_addrs[j]) == 0)
                    students[j] = false;
            }
        }
        else if (count[i] == 3) {
            for (int j = 0; j < ip_addrs.size(); j++) {
                if (ip[i].compare(ip_addrs[j]) == 0) {
                    if (language.compare("0"))
                        language = langs[j];
                    else if (language.compare(langs[j]) != 0)//다르면



                        j는 해다 아이피
                }
            }
        }
    }

    delete[] count;
    return good_participants;
}