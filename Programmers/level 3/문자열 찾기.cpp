// 1. if(index++ == contents.length()) 후위연산자 헷갈리지않게 분리하기
// 2. 문제 정확히 이해


#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string parseShop(string &s) {
    string newS;
    
    for(int i = 0; i < s.length(); i++) {
        if(i + 1 != s.length() && s[i + 1] == '#') {
            char cur = s[i];
            char alpha;
            if(cur == 'C') alpha = 'H';
            if(cur == 'D') alpha = 'I';
            if(cur == 'E') alpha = 'Z';
            if(cur == 'F') alpha = 'J';
            if(cur == 'G') alpha = 'K';
            if(cur == 'A') alpha = 'L';
            newS += alpha;
            i++;
        }
        else {
            newS += s[i];
        }
    }
    return newS;
}

string trimContent(string &contents, int start, int end) {
    int i = 0, index = 0;
    string ret;
    while(i <= end - start) {
        ret += contents[index];
        i++;
        index++;
        if(index == contents.length()) {
            index = 0;
        }
    }
    return ret;
}

pair<string, string> parseAll(string cur, string title, string contents) {
    int start = 60 * (10 * (cur[0] - '0') + cur[1] - '0') + 10 * (cur[3] - '0') + cur[4] - '0';
    int end = 60 * (10 * (cur[6] - '0') + cur[7] - '0') + 10 * (cur[9] - '0') + cur[10] - '0';
    cur.erase(0, 12);
    int pos = cur.find(',');
    title = cur.substr(0, pos);
    cur.erase(0, pos + 1);
    contents = cur;
    contents = parseShop(contents);
    
    contents = trimContent(contents, start, end);
    
    return make_pair(title, contents);
}

bool compare(pair<string, string> a, pair<string, string> b) {
    return a.second.length() > b.second.length();
}

string solution(string m, vector<string> musicinfos) {
    m = parseShop(m);
    
    vector<pair<string, string>> parsed(musicinfos.size());
    for(int i = 0; i < musicinfos.size(); i++) {
        string cur = musicinfos[i];
        parsed[i] = parseAll(cur, "", "");
    }
    
    sort(parsed.begin(), parsed.end(), compare);
    
    for(int i = 0; i < parsed.size(); i++) {
        string cur = parsed[i].second;
        if(cur.find(m) != string::npos) {
            return parsed[i].first;
        }
    }
    
    return "(None)";
}
