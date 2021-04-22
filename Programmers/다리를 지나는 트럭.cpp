#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int total, sec = 0, idx = 0;
    deque<int> bridge;
    for(int i = 0; i < bridge_length; i++)
        bridge.push_back(0);
    
    do {
        total -= bridge.front();
        bridge.pop_front();
        
        if(idx < truck_weights.size() && total + truck_weights[idx] <= weight) {
            bridge.push_back(truck_weights[idx]);
            total += truck_weights[idx++];
        }
        else
            bridge.push_back(0);
        sec++;
    } while(total);
    
    return sec;
}
