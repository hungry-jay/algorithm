#include <string>
#include <vector>

using namespace std;

bool isHIndex(int value, vector<int> citations) {
    int cnt = 0;
    for(int i = 0; i < citations.size(); i++) {
        if(value <= citations[i])
            cnt++;
    }
    return value <= cnt ? true : false;
}

int solution(vector<int> citations) {
    int left = 1, right = citations.size(), mid;
    
    while(left <= right) {
        mid = left + (right - left) / 2;
        isHIndex(mid, citations) ? left = mid + 1 : right = mid - 1;
    }
    
    return right;
}
