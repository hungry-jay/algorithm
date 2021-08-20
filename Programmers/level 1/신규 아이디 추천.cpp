// string 관련 메소드
// s.front(), s.back() ( == s[s.size()-1]) 
// s.begin(), s.end()

#include <string>
#include <vector>

using namespace std;

string stepOne(string s) {
    for(int i = 0; i < s.length(); i++) {
        s[i] = tolower(s[i]);
    }
    return s;
}

string stepTwo(string s) {
    for(int i = 0; i < s.length(); i++) {
        char cur = s[i];
        if(!(islower(cur) || isdigit(cur) || cur == '-' || cur == '_' || cur == '.')) {
            s.erase(i, 1);
            i--;
        }
    }
    return s;
    
}

string stepThree(string s) {
    string nS = "";
    for(int i = 0; i < s.length() - 1; i++) {
        if(s[i] == '.' && s[i + 1] == '.')
            continue;
        nS += s[i];
    }
    nS += s[s.length() - 1];
    return nS;
}

string stepFour(string s) {
    if(s[0] == '.') s.erase(0, 1);
    if(s[s.length() - 1] == '.') s.erase(s.length() - 1, 1);
    return s;
}

string stepFive(string s) {
    if(s.length() == 0) s += "a";
    return s;
}

string stepSix(string s) {
    if(s.length() >= 16) s = s.substr(0, 15);
    if(s[s.length() - 1] == '.') s.erase(s.length() - 1, 1);
    return s;
}

string stepSeven(string s) {
    while(s.length() <= 2) s += s[s.length() - 1];
    return s;
}

string solution(string new_id) {
    new_id = stepOne(new_id);
    new_id = stepTwo(new_id);
    new_id = stepThree(new_id);
    new_id = stepFour(new_id);
    new_id = stepFive(new_id);
    new_id = stepSix(new_id);
    new_id = stepSeven(new_id);
    
    return new_id;
}
