
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 987654321

using namespace std;

vector<pair<int, int>> lecture;
int maxTime = -INF, minTime = INF;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int solve() {
    priority_queue<int, vector<int>, greater<int>> pq;
    sort(lecture.begin(), lecture.end(), cmp);
    int answer = 0;
    pq.push(lecture[0].second);
    
    for(int idx = 1; idx < lecture.size(); idx++) {
        if(lecture[idx].first < pq.top()) 
            pq.push(lecture[idx].second);
            
        if(!pq.empty() && pq.top() <= lecture[idx].first){
            pq.pop();
            pq.push(lecture[idx].second);
        }
        
        if(answer < pq.size())
            answer = pq.size();
    }
    
    return answer;
}

int main() {
    int n, l, r;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &l, &r);
        if(l < minTime)
            minTime = l;
        if(maxTime < r)
            maxTime = r;
        lecture.push_back(make_pair(l, r));
    }
    printf("%d", solve());
    return 0;
}
