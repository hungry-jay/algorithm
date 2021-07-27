// 후위표기식 : 스택 // 헷갈릴때 직접 그려보기

#include <iostream>
#include <stack>

using namespace std;

int priority(char c) {
    if(c == '(') return -1;
    else if(c == '*' || c == '/') return 2;
    else if(c == '+' || c == '-') return 1;
}

string getPostfix(string expression) {
    stack<char> oper;
    string answer;
    for(char cur : expression) {
        if(isupper(cur)) answer += cur;
        else if(cur == '(') oper.push(cur);
        else if(cur == ')') {
            while(oper.top() != '(') {
                answer += oper.top();
                oper.pop();
            }
            oper.pop();
        }
        else {
            while(!oper.empty() && priority(oper.top()) >= priority(cur)) {
                answer += oper.top();
                oper.pop();
            }
            oper.push(cur);
        }
    }
    while(!oper.empty()) {
        answer += oper.top();
        oper.pop();
    }
    return answer;
}

int main() {
    string expression;
    cin >> expression;
    string answer = getPostfix(expression);
    cout << answer << endl;
    return 0;
}
