#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> getAnswer(vector<int> nums) {
    stack<pair<int, int>> S; // idx, value
    vector<int> answer(nums.size());
    S.push(make_pair(0, 0));
    int idx = 1;
    for(int cur : nums) {
        while(!S.empty() && S.top().second < cur)
            S.pop();
        answer[idx - 1] = S.empty() ? 0 : S.top().first;
        S.push(make_pair(idx++, cur));
    }

    return answer;
}

int main() {
    int n;
    vector<int> nums;
    cin >> n;
    nums.resize(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    vector<int> answer = getAnswer(nums);
    for(int num : answer)
        cout << num << " ";
    cout << endl;
    return 0;
}
