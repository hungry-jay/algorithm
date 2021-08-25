#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> turnRight(vector<vector<int>> nums) {
    int temp;
    int n = nums.size() - 1;
    
    for(int i = 0; i < nums.size() / 2; i++) {
        temp = nums[i][n / 2];
        nums[i][n / 2] = nums[i][i];
        nums[i][i] = nums[n / 2][i];
        nums[n / 2][i] = nums[n - i][i];
        nums[n - i][i] = nums[n - i][n / 2];
        nums[n - i][n / 2] = nums[n - i][n - i];
        nums[n - i][n - i] = nums[n / 2][n - i];
        nums[n / 2][n - i] = nums[i][n - i];
        nums[i][n - i] = temp;
    }
    
    return nums;
}

int main(void) {
    int t;
    cin >> t;
    while(t--) {
        int n, d;
        cin >> n >> d;
        vector<vector<int>> nums;

        nums.resize(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int tmp;
                cin >> tmp;
                nums[i].push_back(tmp);
            }
        }

        if(d < 0) d += 360;
        for(int degree = 0; degree < d; degree += 45) {
            nums = turnRight(nums);
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << nums[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
