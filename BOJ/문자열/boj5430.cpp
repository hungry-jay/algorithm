#include <iostream>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

deque<int> dq;
bool forwardDir = true;

bool doTask(string cmd) {
    for(int i = 0; i < cmd.length(); i++) {
        char cur = cmd[i];
        if(cur == 'R')
            forwardDir = forwardDir ? false : true;
        else {
            if(dq.empty())
                return false;
            forwardDir ? dq.pop_front() : dq.pop_back();
        }
    }
    return true;
}

void parseToDeque(string s) {
    int number = 0;
    for(int i = 1; i < s.length(); i++) {
        char cur = s[i];
        if(isdigit(cur)) {
            number *= 10;
            number += cur - '0';
        }
        else {
            if(number)
                dq.push_back(number);
            number = 0;
        }
    }
}

string getAnswer() {
    string answer = "[";
    while(!dq.empty()) {
        if(forwardDir){
            answer += to_string(dq.front());
            dq.pop_front();
        }
        else {
            answer += to_string(dq.back());
            dq.pop_back();
        }
        
        if(dq.empty())
           break;
        answer += ",";
    }
    answer += "]";
    return answer;
}

int main(void) {
    int T, size, tmp;
    string cmd, s, answer;
    
    cin >> T;
    while(T--) {
        forwardDir = true;
        dq.clear();
        cin >> cmd;
        cin >> size;
        cin >> s;
        parseToDeque(s);

        answer = doTask(cmd) ? getAnswer() : "error";
        cout << answer << endl;
    }

    return 0;
}
