#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

bool transformable(string a, string b) {
    int cnt = 0;
    for(int i = 0; i < a.length(); i++)
        if(a[i] != b[i])
            cnt++;
    return cnt == 1 ? true : false;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    queue<pair<string, int>> Q;
    map<string, int> visited;
    Q.push(make_pair(begin, 0));
    visited[begin]++;
    
    while(!Q.empty()) {
        string cur = Q.front().first;
        int depth = Q.front().second;
        Q.pop();
        
        if(cur == target) {
            answer = depth;
            break;
        }
        
        for(int i = 0; i < words.size(); i++) {
            string next = words[i];
            if(transformable(cur, next) && !visited[next]) {
                visited[next]++;
                Q.push(make_pair(next, depth + 1));
            }
        }
    }
    
    return answer;
}
