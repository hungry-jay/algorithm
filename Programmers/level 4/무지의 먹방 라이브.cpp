#include <vector>
#include <queue>
#include <set>

using namespace std;

set<int> isEmpty;

struct compare {
    bool operator() (pair<int, int> a, pair<int, int> b) {
        if(a.first != b.first) return a.first > b.first;
        return a.second > b.second;
    }
};

int consumeRests(vector<int> foodTimes, long long remaining, int size, int count, int consumed) {
    int targetIndex = remaining % size;
    for(int i = 0; i < foodTimes.size(); i++) {
        if(isEmpty.find(i) != isEmpty.end()) continue;

        if(foodTimes[i]) targetIndex--;
        if(targetIndex < 0) {
            return i + 1;
        }
    }
}

bool isAbleToConsume(long long& remaining, int size, int count, int index, int& consumed) {
    long long cur = (long long)size * count;
    if(remaining - cur < 0) {
        return false;
    }
    remaining -= cur;
    consumed += count;
    isEmpty.insert(index);
    return true;
}

int solution(vector<int> food_times, long long remaining) {
    int consumed = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    for(int i = 0; i < food_times.size(); i++) {
        pq.push(make_pair(food_times[i], i));
    }

    while(!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();
        cur.first -= consumed;
        if(!isAbleToConsume(remaining, pq.size() + 1, cur.first, cur.second, consumed)) {
            return consumeRests(food_times, remaining, pq.size() + 1, cur.first, consumed);
        }
    }
    return -1;
}
