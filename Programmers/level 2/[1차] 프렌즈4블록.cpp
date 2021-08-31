// 로직 분리해서 심플하게 만들기

#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

int visited[30][30] = {0, };

bool anyChecked(int m, int n) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(visited[i][j] == 1) return true;
        }
    }
    return false;
}

void checkBoard(vector<string> board, int y, int x) {
    char cur = board[y][x];
    if(cur == ' ') return;
    if(cur == board[y + 1][x] && cur == board[y][x + 1] && cur == board[y + 1][x + 1]) {
        visited[y][x] = 1;
        visited[y + 1][x] = 1;
        visited[y][x + 1] = 1;
        visited[y + 1][x + 1] = 1;
    }
}

void moveBoard(vector<string> &board, int m, int n) {
    for(int j = 0; j < n; j++) {
        int target = m - 1;
        while(target >= 0) {
            if(board[target][j] != ' ') {
                target--;
                continue;
            }
            
            int cur = target - 1;
            while(cur >= 0 && board[cur][j] == ' ') {
                cur--;
            }
            
            if(cur >= 0) {
                board[target][j] = board[cur][j];
                board[cur][j] = ' ';
            }
            else {
                board[target][j] = ' ';
            }
            target--;
        }
    }
}

int countDeleted(vector<string> board, int m, int n) {
    int count = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] == ' ') {
                count++;
            }
        }
    }
    return count;
}

void deleteVisited(vector<string> &board, int m, int n) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            board[i][j] = visited[i][j] ? ' ' : board[i][j];
        }
    }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    do {
        memset(visited, 0, sizeof(visited));
        for(int i = 0; i < board.size() - 1; i++) {
            for(int j = 0; j < board[i].length() - 1; j++) {
                checkBoard(board, i, j);
            }
        }
        
        deleteVisited(board, m, n);
        moveBoard(board, m, n);
        
    } while(anyChecked(m, n));
    
    answer = countDeleted(board, m, n);
    
    return answer;
}
