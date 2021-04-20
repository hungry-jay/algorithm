#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    vector<int> nums;
    map<int, int> M;
    int n, k, maxLength = 0, lo = 0, hi = 0;
    cin >> n >> k;
    nums.resize(n);
    
    for(int i = 0; i < n; i++)
        cin >> nums[i];
        
    M[nums[0]]++;
    
    while(hi < n) {
        if(M[nums[hi]] <= k) {
            if(maxLength < hi - lo + 1)
                maxLength = hi - lo + 1;
            hi++;
            M[nums[hi]]++;
        }
        else {
            M[nums[lo]]--;
            lo++;
        }
    }
    
    cout << maxLength << endl;
    
    return 0;
}
