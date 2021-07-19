#include <iostream>
#include <stack>

using namespace std;

bool isRightBrackets(string brackets) {
    stack<char> s;
    for(char cur : brackets) {
        if(cur == '[' || cur == '(')
            s.push(cur);
        else {
            if(s.empty() || (s.top() == '(' && cur == ']') || (s.top() == '[' && cur == ')'))
                return false;
            else
                s.pop();
        }
    }
    if(!s.empty())
        return false;

    return true;
}

int getAnswer(string brackets) {
    stack<int> s;
    int temp = 1;
    for(char cur : brackets) {
        if(cur == '[' || cur == '(') {
            if(temp != 1) {
                s.push(-1 * temp);
                temp = 1;
            }
            if(cur == '(')
                s.push(2);
            else
                s.push(3);
        }
        else {
            if(cur == ')')
                temp *= 2;
            else if(cur == ']')
                temp *= 3;
            s.pop();
            if(!s.empty() && s.top() < 0) {
                temp += (-1 * s.top());
                s.pop();
            }
        }
    }

    return temp;
}

int main() {
    string brackets;
    cin >> brackets;

    int answer = isRightBrackets(brackets) ? getAnswer(brackets) : 0;
    cout << answer << endl;

    return 0;
}
