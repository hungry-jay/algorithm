// 조합 + 중복 검사

#include <string>
#include <vector>
#include <set>

using namespace std;

vector<string> candidates;
vector<vector<string>> table;
int maxNumber;

bool isCandidate(string indexes) {
    set<string> s;
    
    for(int i = 0; i < table.size(); i++) {
        string cur;
        for(int j = 0; j < indexes.length(); j++) {
            cur += table[i][indexes[j] - '0'];
        }
        
        if(s.find(cur) == s.end()) {
            s.insert(cur);
        }
        else return false;
    }
    
    return true;
}

bool isDuplicated(string indexes) {
    for(int i = 0; i < candidates.size(); i++) {
        string cur = candidates[i];
        
        bool anyDiff = false;
        for(int j = 0; j < cur.length(); j++) {
            if(indexes.find(cur[j]) == string::npos) {
                anyDiff = true;
            }
        }
        if(!anyDiff) return true;
    }
    return false;
}

void visit(string cur, int num, int depth, int c) {
    if(num == depth) {
        if(isCandidate(cur) && !isDuplicated(cur)) {
            candidates.push_back(cur);
        }
        return;
    }
    
    for(int i = c; i < maxNumber; i++) {
        visit(cur + to_string(i), num, depth + 1, i + 1);
    }
}

int solution(vector<vector<string>> relation) {
    table = relation;
    maxNumber = relation[0].size();
    
    for(int num = 1; num <= maxNumber; num++) {
        visit("", num, 0, 0);
    }
    
    return candidates.size();
}
