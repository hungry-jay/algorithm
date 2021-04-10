#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPossible(int* visit) {
    bool flag = false;
    for(int i = 0; i < 26; i++) {
        if(visit[i] && visit[i] & 1) {
            if(flag)
                return false;
            flag = true;
        }
    }
    return true;
}

int main() {
    string s, prefix = "", mid = "", suffix = "";
    int visit[26] = {0, };
    cin >> s;
    for(int i = 0; i < s.length(); i++)
        visit[s[i] - 'A']++;
    
    if(!isPossible(visit)) {
        cout << "I'm Sorry Hansoo" << endl;
        return 0;
    }
    
    for(int i = 0; i < 26; i++) {
        int cur = visit[i];
        if(cur) {
            if(cur & 1)
                mid += 'A' + i;
            
            for(int j = 0; j < cur / 2; j++)
                prefix += 'A' + i;
        }
    }
    
    suffix = prefix;
    reverse(suffix.begin(), suffix.end());
    
    if(mid.length())
        prefix += mid;
    
    cout << prefix + suffix << endl;
    return 0;
}
