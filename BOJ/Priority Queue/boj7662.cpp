#include <iostream>
#include <queue>

using namespace std;
#define MAX 1000001

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> maxHeap;

        int visited[MAX] = { 0, };
        int k;
        cin >> k;
        int count = 0;
        for(int i = 0; i < k; i++) {
            char cmd;
            int num;
            cin >> cmd >> num;
            if(cmd == 'I') {
                minHeap.push(make_pair(num, i));
                maxHeap.push(make_pair(num, i));
                count++;
            }
            else {
                if(!count)
                    continue;

                if(num > 0) {
                    while(visited[maxHeap.top().second])
                        maxHeap.pop();
                    visited[maxHeap.top().second] = 1;
                    maxHeap.pop();
                    count--;
                }
                else {
                    while(visited[minHeap.top().second])
                        minHeap.pop();
                    visited[minHeap.top().second] = 1;
                    minHeap.pop();
                    count--;
                }
            }
        }

        if(!count)
            cout << "EMPTY" << endl;
        else {
            while(visited[maxHeap.top().second]) {
                maxHeap.pop();
            }
            while(visited[minHeap.top().second]) {
                minHeap.pop();
            }
            cout << maxHeap.top().first << " " << minHeap.top().first << endl;
        }
    }

    return 0;
}
