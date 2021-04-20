#include <iostream>
#include <map>
#include <vector>

/*  결국엔 hi가 끝난 시점이면 이미 최선을 찾은경우. 
*/

#define INF 987654321

using namespace std;

int main() {
    int n, upperBound, lo = 0, hi = 0, minLength = INF, sum = 0;
    cin >> n >> upperBound;
    vector<int> nums;
    nums.resize(n);

    for(int i = 0; i < n; i++) 
        cin >> nums[i];

    sum = nums[0];
    while(1) {
        if(upperBound <= sum) {
            if(hi - lo + 1 < minLength)
                minLength = hi - lo + 1;
                
            sum -= nums[lo];
            lo++;
        }
        else {
            hi++;
            if(hi == n)
                break;
            sum += nums[hi];
        }
    }
    
    minLength = minLength == INF ? 0 : minLength;
    cout << minLength << endl;
    
    return 0;
}
