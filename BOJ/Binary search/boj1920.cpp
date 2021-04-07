#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int mid;

    while(left <= right) {
        mid = left + (right - left) / 2;
        if(nums[mid] == target) return true;
        target < nums[mid] ? right = mid - 1 : left = mid + 1;
    }

    return false;
}

int main(void) {
    int n, m, target;
    vector<int> nums;
    scanf("%d", &n);
    nums.resize(n);
    for(int i = 0; i < n; i++) 
        scanf("%d", &nums[i]);
    scanf("%d", &m);

    sort(nums.begin(), nums.end());
    for(int i = 0; i < m; i++) {
        scanf("%d", &target);
        printf("%d\n", solution(nums, target));
    }
    return 0;
}
