#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> indexes;

bool isAvailable(string a, string b) {
    if(a.length() != b.length()) return false;
    
    for(int i = 0; i < b.length(); i++) {
        if(b[i] == '*' || a[i] == b[i]) {
            continue;
        }
        return false;
    }
    
    return true;
}

void doVisit(vector<string> users, vector<string> banneds, vector<int> visited, int depth) {
    if(depth == banneds.size()) {
        string index;
        for(int i = 0; i < visited.size(); i++) {
            if(visited[i]) index += to_string(i);
        }
        indexes.push_back(index);
        return;
    }
    
    string target = banneds[depth];
    for(int i = 0; i < users.size(); i++) {
        string cur = users[i];
        if(isAvailable(cur, target) && visited[i] == 0) {
            visited[i] = 1;
            doVisit(users, banneds, visited, depth + 1);
            visited[i] = 0;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    vector<int> visited(10);
    doVisit(user_id, banned_id, visited, 0);
    
    sort(indexes.begin(), indexes.end());
    indexes.erase(unique(indexes.begin(), indexes.end()), indexes.end());
    return indexes.size();
}
