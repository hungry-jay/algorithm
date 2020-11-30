#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int nums[5][5];
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};
vector<string> list;

void input() {
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            cin >> nums[i][j];
}

void dfs(int y, int x, string s){
    s += to_string(nums[y][x]);
    
    if(s.length() == 6){
        list.push_back(s);
        return;
    }
    
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(0 <= ny && 0 <= nx && ny < 5 && nx < 5){
            dfs(ny, nx, s);
        }
    }
}

int main() {
    input();
    
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            dfs(i, j, "");
            
    sort(list.begin(), list.end());
    list.erase(unique(list.begin(), list.end()), list.end());
    cout << list.size() << endl;
    
    return 0;
}
