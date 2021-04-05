#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define MAX 2005

int n, m;
vector<int> nums;
bool dp[MAX][MAX];

bool isPalindrome(int from, int to) {
    if(from == to || (from + 1 == to && nums[from] == nums[to]) || dp[from][to]) {
        dp[from][to] = true;
        return true;
    }
    
    if(from > to)
        return false;

    return dp[from][to] = isPalindrome(from + 1, to - 1) && nums[from] == nums[to] ? true : false;
}

void input() {
    scanf("%d", &n);
    nums.resize(MAX);
    for(int i = 0; i < n; i++)
        scanf("%d", &nums[i]);
    
    scanf("%d", &m);
}

int main(void) {
    input();
    memset(dp, false, sizeof(dp));
    int from, to;
    
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &from, &to);
        isPalindrome(from - 1, to - 1) ? printf("1\n") : printf("0\n");
    }
    return 0;
}
