#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> getEachTuple(string s) {
    vector<int> tuple;
    
    int pos = 0;
    string token;
    while((pos = s.find(',')) != string::npos) {
        token = s.substr(0, pos);
        tuple.push_back(stoi(token));
        s.erase(0, pos + 1);
    }
    tuple.push_back(stoi(s));
    
    return tuple;
}

vector<vector<int>> parse(string s) {
    vector<vector<int>> parsed;
    int startPos = 0;
    
    s.erase(0, 1);
    while((startPos = s.find('{')) != string::npos) {
        int endPos = s.find('}');
        string tmp = s.substr(startPos + 1, endPos - startPos - 1);
        vector<int> tuple = getEachTuple(tmp);
        s.erase(0, endPos + 1);
        parsed.push_back(tuple);
    }
    
    return parsed;
}

bool cmp(vector<int> a, vector<int> b) {
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> parsed = parse(s);
    
    set<int> nums;
    
    sort(parsed.begin(), parsed.end(), cmp);
    
    for(int i = 0; i < parsed.size(); i++) {
        for(int j = 0; j < parsed[i].size(); j++) {
            int cur = parsed[i][j];
            if(nums.find(cur) == nums.end()) {
                answer.push_back(cur);
                nums.insert(cur);
            }
        }
    }
    
    return answer;
}
