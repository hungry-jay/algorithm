// BFS

#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

bool isInRange(int y, int x) {
    return 0 <= y && 0 <= x && y < 5 && x < 5;
}

bool bfs(int y, int x, int depth, vector<string> places) {
    queue<pair<int, int>> Q;
    Q.push(make_pair(y, x));
    int visited[5][5] = {0, };
    
    visited[y][x] = 1;
    
    while(!Q.empty()) {
        int y = Q.front().first;
        int x = Q.front().second;
        
        Q.pop();
        
        if((visited[y][x] == 2 || visited[y][x] == 3) && places[y][x] == 'P')
            return false;
        
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(isInRange(ny, nx) && !visited[ny][nx] && places[ny][nx] != 'X') {
                Q.push(make_pair(ny, nx));
                visited[ny][nx] = visited[y][x] + 1;
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(int i = 0; i < places.size(); i++) {
        bool subAnswer = true;
        for(int j = 0; j < 5; j++) {
            for(int k = 0; k < 5; k++) {
                if(places[i][j][k] == 'P') {
                    if(!bfs(j, k, 0, places[i]))
                        subAnswer = false;
                }
            }
        }
        subAnswer ? answer.push_back(1) : answer.push_back(0);
    }
    
    
    return answer;
}
