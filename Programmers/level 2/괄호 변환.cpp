#include <string>
#include <vector>

using namespace std;

bool isBalanced(string s) {
    int count = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(') count++;
        else count--;
    }
    return count == 0 ? true : false;
}

bool isCorrect(string s) {
    int count = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(') count++;
        else count--;
        
        if(count < 0) return false;
    }
    return count == 0 ? true : false;
}

string solution(string p) {
    // cond 1
    if(p.length() == 0) return "";
    
    // cond 2
    string u;
    string v;
    for(int i = 2; i <= p.length(); i++) {
        u = p.substr(0, i);
        v = p.substr(i, p.length() - i);
        if(isBalanced(u) && isBalanced(v)) {
            break;
        }
    }
    
    // cond 3
    if(isCorrect(u)) {
        return u + solution(v);
    }
    else {    // cond 4
        string newV;
        newV += "(";
        newV += solution(v);
        newV += ")";

        u = u.substr(1, u.length() - 1);
        u.erase(u.length() - 1, 1);
        
        string newU;
        for(int j = 0; j < u.length(); j++) {
            newU += u[j] == '(' ? ")" : "(";
        }
        return newV + newU;
    }
}
