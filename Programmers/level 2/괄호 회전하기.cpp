#include <string>
#include <vector>
#include <stack>

using namespace std;

string rotate(string s) {
    char cur = s[0];
    s = s.substr(1);
    s += cur;
    return s;
}

bool isCorrectString(string s) {
    stack<char> S;
    
    for(int i = 0; i < s.length(); i++) {
        char cur = s[i];
        if(cur == ']' || cur == '}' || cur == ')') {
            if(S.empty()) return false;
            if(
                (S.top() == '[' && cur == ']') ||
                (S.top() == '{' && cur == '}') ||
                (S.top() == '(' && cur == ')')
              ) {
                S.pop();
            }
            else return false;
        }
        else {
            S.push(cur);
        }
    }
    return S.empty() ? true : false;
}

int solution(string s) {
    int answer = 0;
    for(int i = 0; i < s.length(); i++) {
        if(isCorrectString(s)) answer++;
        s = rotate(s);
    }
    return answer;
}
