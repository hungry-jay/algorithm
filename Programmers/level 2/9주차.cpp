#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

#define INF 987654321

bool visited[101] = { false, };

bool isRemoved(int i, int j, int from, int to) {
    return (i == from && j == to) || (i == to && j == from);
}

int travel(vector<vector<int>> adj, int cur, int from, int to) {
    int count = 0;
    queue<int> Q;
    Q.push(cur);
    visited[cur] = true;
    while(!Q.empty()) {
        count++;
        int curFrom = Q.front();
        Q.pop();
        for(int i = 0; i < adj[curFrom].size(); i++) {
            int curTo = adj[curFrom][i];
            if(!visited[curTo] && !isRemoved(curFrom, curTo, from, to)) {
                Q.push(curTo);
                visited[curTo] = true;
            }
        }
    }
    return count;
}

int getCurrentDiff(int n, vector<vector<int>> adj, int from, int to) {
    vector<int> treeNodeCount;
    
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            int count = travel(adj, i, from, to);
            treeNodeCount.push_back(count);
        }
    }
    
    return abs(treeNodeCount[0] - treeNodeCount[1]);
}

int solution(int n, vector<vector<int>> wires) {
    int answer = INF;
    vector<vector<int>> adj(n + 1);
    
    for(int i = 0; i < wires.size(); i++) {
        int from = wires[i][0];
        int to = wires[i][1];
        
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    
    for(int i = 0; i < wires.size(); i++) {
        memset(visited, false, sizeof(visited));
        int from = wires[i][0];
        int to = wires[i][1];
        
        int cur = getCurrentDiff(n, adj, from, to);
        if(cur < answer) {
            answer = cur;
        }
    }
    return answer;
}
