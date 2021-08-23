#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> parse(string s) {
    vector<string> parsed;
    
    int pos = 0;
    string token;
    while((pos = s.find(" ")) != string::npos) {
        token = s.substr(0, pos);
        parsed.push_back(token);
        s.erase(0, pos + 1);
    }
    parsed.push_back(s);
    return parsed;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    vector<pair<string, string>> uuidAndAction;
    map<string, string> uuidToName;
    
    int idx = 0;
    for(int i = 0; i < record.size(); i++) {
        vector<string> cur = parse(record[i]);
        
        string action = cur[0];
        string uuid = cur[1];
        
        if(action == "Enter") {
            string name = cur[2];
            uuidAndAction.push_back(make_pair(uuid, action));
            uuidToName[uuid] = name;
            idx++;
        }
        else if(action == "Leave") {
            uuidAndAction.push_back(make_pair(uuid, action));
            idx++;
        }
        else if(action == "Change") {
            string name = cur[2];
            uuidToName[uuid] = name;
        }
    }
    
    for(int i = 0; i < uuidAndAction.size(); i++) {
        string cur;
        
        string uuid = uuidAndAction[i].first;
        string action = uuidAndAction[i].second;
        
        string name = uuidToName[uuid];
        cur += name;
        
        if(action == "Enter") {
            cur += "님이 들어왔습니다.";
        }
        else if(action == "Leave") {
            cur += "님이 나갔습니다.";
        }
        
        answer.push_back(cur);
    }
    
    return answer;
}
