#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int n;
int board[10][10];
int visited[10][10];
int sum = 0;
int dy[] = {-1, 1, 1, -1};
int dx[] = {1, 1, -1, -1};

void input() {
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];
}

bool check(int y, int x) {
    for(int w = 1; w < n; w++){
        for(int i = 0; i < 4; i++){
            int ny = y + w * dy[i];
            int nx = x + w * dx[i];
            if(0 <= nx && nx < n && 0 <= ny && ny < n)
                if(visited[ny][nx])
                    return false;
        }
    }
    return true;
}

void backTrack(queue<pair<int, int>> Q, int count) {
    if(sum < count)
        sum = count;

    if (Q.empty())
        return;
    
    int y = Q.front().first;
    int x = Q.front().second;
    Q.pop();

    backTrack(Q, count);
    if(check(y, x)){
        visited[y][x] = 1;
        backTrack(Q, count + 1);
        visited[y][x] = 0;
    }
}

void makeQueue(queue<pair<int, int>> &firstQ, queue<pair<int, int>> &secondQ) {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(board[i][j] == 1)
                (i + j) & 1 ? secondQ.push(make_pair(i, j)) : firstQ.push(make_pair(i, j));
}

int main(void) {
    int answer = 0;
    input();
    queue<pair<int, int>> firstQ, secondQ;
    makeQueue(firstQ, secondQ);

    memset(visited, 0, sizeof(visited));
    backTrack(firstQ, 0);
    answer += sum;
    
    memset(visited, 0, sizeof(visited));
    sum = 0;
    backTrack(secondQ, 0);
    answer += sum;

    cout << answer << endl;
    return 0;
}
