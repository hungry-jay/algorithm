
#include <iostream>
#include <vector>

using namespace std;

int answer = -1;
int visited[101] = {0, };

void find(vector<vector<int>> relation, int cur, int target, int depth) {
    if(cur == target) {
        answer = depth;
        return;
    }
    
    for(int i = 0; i < relation[cur].size(); i++) {
        if(!visited[relation[cur][i]]) {
            visited[relation[cur][i]] = 1;
            find(relation, relation[cur][i], target, depth + 1);
            visited[relation[cur][i]] = 0;
        }
    }
}
    
int main() {
    int x, y, n, me, target, m;
    cin >> n;
    cin >> me >> target;
    cin >> m;
    vector<vector<int>> relation(n + 1);
    for(int i = 0; i < m; i++) {
        cin >> x >> y;
        relation[x].push_back(y);
        relation[y].push_back(x);
    }
    visited[me] = 1;
    find(relation, me, target, 0);
    
    cout << answer << endl;
    
    return 0;
}
