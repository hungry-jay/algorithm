#include <iostream>
#include <cstring>

#define INF 987654321

using namespace std;

int n, answer = INF, cities[11][11];
bool visited[11];

void init() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> cities[i][j];
        }
    }
    memset(visited, false, sizeof(visited));
}

void solve(int first, int depth, int cur, int sum) {
    if(depth == n) {
        if(answer > sum)
            answer = sum;
        return;
    }
    
    for(int i = 0; i < n; i++) {
        if(!visited[i] && cities[cur][i]) {
            visited[i] = true;
            solve(first, depth + 1, i, sum + cities[cur][i]);
            visited[i] = false;
        }
    }
    
    if(depth + 1 == n && cities[cur][first])
        solve(first, depth + 1, first, sum + cities[cur][first]);
}

int main() {
    init();
    for(int i = 0; i < n; i++) {
        visited[i] = true;
        solve(i, 0, i, 0);
        visited[i] = false;
    }
    cout << answer << endl;
    return 0;
}
