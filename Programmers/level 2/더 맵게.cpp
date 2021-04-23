#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> PQ;
    for(int i = 0; i < scoville.size(); i++)
        PQ.push(scoville[i]);
    
    while(K > PQ.top()) {
        if(PQ.size() == 1)
            return -1;
        answer++;
        int first = PQ.top();
        PQ.pop();
        int second = PQ.top();
        PQ.pop();
        PQ.push(first + second * 2);
    }
    
    return answer;
}
