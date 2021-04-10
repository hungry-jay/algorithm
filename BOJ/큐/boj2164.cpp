#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> Q;
    int n, last;
    cin >> n;
    
    for(int i = 1; i <= n; i++)
        Q.push(i);
    
    while(!Q.empty()) {
        last = Q.front();
        Q.pop();
        if(Q.empty())
            break;
        
        last = Q.front();
        Q.pop();
        Q.push(last);
    }
    
    cout << last << endl;
    
    return 0;
}
