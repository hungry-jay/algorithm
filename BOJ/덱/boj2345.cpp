/* 조건문 범위 명확히 명시하기 */

#include <iostream>
#include <deque>

using namespace std;

int main(void) {
    deque<pair<int, int>> dq;
    int n, tmp, move = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> tmp;
        dq.push_back(make_pair(i, tmp));
    }
    
    while(1) {
        if(move > 0) {
            move--;
            int first = dq.front().first;
            int second = dq.front().second;
            dq.pop_front();
            dq.push_back(make_pair(first, second));
        }
        else if(move < 0) {
            move++;
            int first = dq.back().first;
            int second = dq.back().second;
            dq.pop_back();
            dq.push_front(make_pair(first, second));
        }
        else {
            cout << dq.front().first << " ";
            move = dq.front().second;
            if(move > 0)
                move--;
            dq.pop_front();
        }
        
        if(dq.empty())
            break;
    }
    
    return 0;
}
