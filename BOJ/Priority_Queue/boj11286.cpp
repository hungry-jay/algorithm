#include <iostream>
#include <queue>
// greater<> 오름차순  // less<> 내림차순

using namespace std;

struct compare {
    bool operator()(int a, int b) {
        if(abs(a) != abs(b))
            return abs(a) > abs(b);
        else
            return a > b;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    priority_queue<int, vector<int>, compare> pq;

    int n, num;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> num;
        if(!num) {
            if (!pq.empty()) {
                cout << pq.top() << "\n";
                pq.pop();
            }
            else
                cout << 0 << "\n";
        }
        else
            pq.push(num);
    }

    return 0;
}
