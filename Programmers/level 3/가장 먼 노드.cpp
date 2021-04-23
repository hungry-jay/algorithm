#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void go(vector<vector<int>> paths, vector<int> &visited) {
    queue<int> Q;
    Q.push(1); // start node
    visited[1] = 1;
    
    while(!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        
        for(int i = 0; i < paths[cur].size(); i++) {
            int next = paths[cur][i];
            if(!visited[next]) {
                visited[next] = visited[cur] + 1;
                Q.push(next);
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0, from, to;
    vector<vector<int>> paths(n + 1);
    vector<int> visited(n + 1, 0);
    for(int i = 0; i < edge.size(); i++) {
        from = edge[i][0];
        to = edge[i][1];
        paths[from].push_back(to);
        paths[to].push_back(from);
    }
    
    go(paths, visited);
    int furthest = *max_element(visited.begin(), visited.end());
    
    for(int i = 1; i <= n; i++)
        if(visited[i] == furthest)
            answer++;
    return answer;
}
