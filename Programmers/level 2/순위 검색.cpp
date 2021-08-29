// key point
// 1. map<string, vector<int>>
// 2. 이분탐색 경계기준


#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, vector<int>> m;

vector<vector<string>> parse(vector<string> info, string delimeter) {
    vector<vector<string>> parsed;
    
    for(int i = 0; i < info.size(); i++) {
        int pos = 0;
        string cur = info[i];
        string token;
        vector<string> tokens;
        while((pos = cur.find(delimeter)) != string::npos) {
            token = cur.substr(0, pos);
            tokens.push_back(token);
            cur.erase(0, pos + delimeter.length());
        }
        
        if((pos = cur.find(" ")) != string::npos) {
            token = cur.substr(0, pos);
            tokens.push_back(token);
            cur.erase(0, pos + 1);
        }
        
        tokens.push_back(cur);
        parsed.push_back(tokens);
    }
    
    return parsed;
}

// dfs
void setEachCase(vector<string> info, int depth, string cur) {
    if(depth == 4) {
        m[cur].push_back(stoi(info[4]));
        return;
    }
    
    setEachCase(info, depth + 1, cur + info[depth]);
    setEachCase(info, depth + 1, cur + "-");
}

void setMap(vector<vector<string>> info) {
    for(int i = 0; i < info.size(); i++) {
        vector<string> cur = info[i];
        setEachCase(cur, 0, "");
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    vector<vector<string>> parsedInfo = parse(info, " ");
    vector<vector<string>> parsedQuery = parse(query, " and ");
    
    setMap(parsedInfo);
    
    for(auto iter = m.begin(); iter != m.end(); iter++) {
        sort(iter->second.begin(), iter->second.end());
    }
    
    for(int i = 0; i < parsedQuery.size(); i++) {
        vector<string> cur = parsedQuery[i];
        string query = cur[0] + cur[1] + cur[2] + cur[3];
        int requiredScore = stoi(cur[4]);
        
        vector<int> values = m[query];
        
        int idx = lower_bound(values.begin(), values.end(), requiredScore) - values.begin();
        
        answer.push_back(values.size() - idx);
    }
       
    return answer;
}
