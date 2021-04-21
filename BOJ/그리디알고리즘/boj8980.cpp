/*
  도착시간을 기준으로 정렬하는 것은 바로 떠올렸지만 
  contains로 관리하는것이 핵심
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<pair<int, int>, int>> boxes;
vector<int> contains;

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    return a.first.second < b.first.second;
}

int solve(int capacity) {
    sort(boxes.begin(), boxes.end(), cmp);
    
    int from, to, weight, answer = 0, part;
    for(int i = 0; i < boxes.size(); i++) {
        from = boxes[i].first.first;
        to = boxes[i].first.second;
        weight = boxes[i].second;
        part = weight;
        
        for(int j = from; j < to; j++) 
            if(contains[j] + part > capacity)
                part = capacity - contains[j];
                
        if(!part)
            continue;
            
        for(int j = from; j < to; j++) {
            contains[j] += part;
        }
        answer += part;
    }
    return answer;
}

int main() {
    int n, capacity, m;
    cin >> n >> capacity;
    cin >> m;
    boxes.resize(m);
    contains.resize(n + 1);
    for(int i = 0; i < m; i++) 
        cin >> boxes[i].first.first >> boxes[i].first.second >> boxes[i].second;

    cout << solve(capacity) << endl;
    return 0;
}
