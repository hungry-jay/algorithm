// 복잡한 조건문 인덱스 따라가며 디버깅

#include <string>
#include <vector>
#include <map>

using namespace std;

void init(map<string, int> &m) {
    for(int i = 0; i < 26; i++) {
        string cur;
        cur += 'A' + i;
        m[cur] = i + 1;
    }
}

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> dict;
    init(dict);
    int idx = 0;
    int num = 27;
    
    while(1) {
        bool isFound = true;
        string cur = "";
        while(1) {
            cur += msg[idx];
            if(dict.find(cur) == dict.end()) {
                isFound = false;
                string prev = cur.substr(0, cur.size() - 1);
                answer.push_back(dict[prev]);
                dict[cur] = num;
                num++;
                break;
            }
            idx++;
            if(idx == msg.length()) {
                answer.push_back(dict[cur]);
                return answer;
            }
        }
    }
}
