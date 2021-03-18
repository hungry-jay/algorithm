#include <vector>
#include <queue>
#include <cstring>

using namespace std;

// 오랜만에 알고리즘,, BFS

bool isInRange(int ny, int nx, int maxY, int maxX) {
    return ny >= 0 && nx >= 0 && maxY > ny && maxX > nx;
}

int search(int y, int x, vector<vector<int> > maps) {
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    int ny, nx, maxY = maps.size(), maxX = maps[0].size();
    int visited[100][100];
    memset(visited, -1, sizeof(visited));
    visited[0][0] = 1;
    
    queue<pair<int, int>> Q;
    Q.push(make_pair(y, x));
    
    while(!Q.empty()) {
        y = Q.front().first;
        x = Q.front().second;
        Q.pop();
        
        for(int i = 0; i < 4; i++) {
            ny = y + dy[i];
            nx = x + dx[i];
            if(isInRange(ny, nx, maxY, maxX) && visited[ny][nx] == -1 && maps[ny][nx]) {
                if(ny == maxY - 1 && nx == maxX - 1)
                    return visited[y][x] + 1;
                visited[ny][nx] = visited[y][x] + 1;
                Q.push(make_pair(ny, nx));
            }
        }
    }
    return -1;
}

int solution(vector<vector<int> > maps)
{
    return search(0, 0, maps);
}
