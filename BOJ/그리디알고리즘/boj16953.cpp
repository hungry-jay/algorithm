#include <iostream>

// bfs도 가능할듯

using namespace std;
int minDepth = 987654321;

void solve(int cur, int target, int depth) {
    if(cur == target) {
        if(depth < minDepth)
            minDepth = depth;
        return;
    }
    
    if(cur > target)
        return;
        
    solve(cur * 2, target, depth + 1);
    
    if(cur * 10 > target)
        return;
        
    int appended = stoi(to_string(cur) + "1");
    solve(appended, target, depth + 1);
}

int main(void) {
    int a, b;
    cin >> a >> b;
    solve(a, b, 1);
    int answer = minDepth != 987654321 ? minDepth : -1;
    cout << answer << endl;
}
