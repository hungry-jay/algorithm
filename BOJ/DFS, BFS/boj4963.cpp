#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

bool visited[50][50];
int map[50][50];
int w, h;
int dx[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dy[] = { -1, 0, 1, 1, 1, 0, -1, -1 };

bool isInBound(int y, int x) {
    return 0 <= y && 0 <= x && y < h && x < w;
}

void go(int y, int x) {
    visited[y][x] = true;
    
    for(int i = 0; i < 8; i++) {
        int ny = dy[i] + y;
        int nx = dx[i] + x;
        if(isInBound(ny, nx) && !visited[ny][nx] && map[ny][nx])
            go(ny, nx);
    }
}

int main()
{
    while(1) {
        int answer = 0;
        cin >> w >> h;
        if(!w && !h)
            break;
        
        memset(map, 0, sizeof(map));
        memset(visited, false, sizeof(visited));
        for(int i = 0; i < h; i++)
            for(int j = 0; j < w; j++) 
                cin >> map[i][j];
        
        for(int i = 0; i < h; i++)
            for(int j = 0; j < w; j++)
                if(!visited[i][j] && map[i][j]) {
                    go(i, j);
                    
                    answer++;
                }
        cout << answer << endl;
    }

    return 0;
}
