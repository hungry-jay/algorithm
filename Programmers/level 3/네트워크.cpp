#include <string>
#include <vector>
#include <iostream>

using namespace std;

void go(vector<vector<int>> computers, vector<bool> &visited, int cur) {
    visited[cur] = true;
    for(int i = 0; i < computers[cur].size(); i++) {
        if(!visited[i] && computers[cur][i]) {
            go(computers, visited, i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(computers.size(), false);
    
    for(int i = 0; i < n; i++) {
        if(visited[i])
            continue;
        
        answer++;
        go(computers, visited, i);
    }
    
    return answer;
}
