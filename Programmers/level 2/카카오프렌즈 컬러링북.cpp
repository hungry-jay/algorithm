#include <vector>
#include <queue>
#include <map>
#include <cstring>

using namespace std;

int visited[100][100] = { 0, };
int areaNum = 0;

bool isInRange(int y, int x, int m, int n) {
    return 0 <= y && 0 <= x && y < m && x < n;
}

void travel(vector<vector<int>> map, int y, int x, int m, int n) {
    if(map[y][x] == 0 || visited[y][x]) {
        return;
    }
    
    int dy[] = { 0, 1, 0, -1 };
    int dx[] = { 1, 0, -1, 0 };
    
    areaNum++;
    queue<pair<int, int>> Q;
    Q.push(make_pair(y, x));
    visited[y][x] = areaNum;
    
    while(!Q.empty()) {
        y = Q.front().first;
        x = Q.front().second;
        Q.pop();
        
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(
                isInRange(ny, nx, m, n) &&
                map[y][x] == map[ny][nx] &&
                visited[ny][nx] == 0
              ) {
                visited[ny][nx] = areaNum;
                Q.push(make_pair(ny, nx));
            }
        }
    }
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    map<int, int> sizes;
    
    vector<int> answer(2);
    
    memset(visited, 0, sizeof(visited));
    areaNum = 0;
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            travel(picture, i, j, m, n);
        }
    }
        
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(number_of_area < visited[i][j]) {
                number_of_area = visited[i][j];
            }
            if(picture[i][j]) {
                sizes[visited[i][j]]++;
            }
        }
    }
    
    for(auto iter = sizes.begin(); iter != sizes.end(); iter++) {
        if(max_size_of_one_area < iter->second) {
            max_size_of_one_area = iter->second;
        }
    }
    
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
