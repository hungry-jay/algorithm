#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

// 그냥 적당히 수 규칙 찾고 조건 생각하면 되는 문제

using namespace std;

int main(void) {
	vector<int> nums;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		nums.push_back(tmp);
	}
	
	sort(nums.begin(), nums.end(), greater<int>());

	int idx = -1;

	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == 0 || (1 <= i && nums[i] * nums[i - 1] < 0)) {
			idx = i;
			break;
		}
	}

	int sum = 0;
	if (idx != -1) {
		vector<int> positive(nums);
		vector<int> negative(nums);
		positive.erase(positive.begin() + idx, positive.end());
		negative.erase(negative.begin(), negative.begin() + idx);
		sort(negative.begin(), negative.end());

		for (int i = 0; i < positive.size(); i++) {
			if (i & 1 && (positive[i] == 1 || positive[i - 1] == 1)) {
				sum += positive[i] + positive[i - 1];
				continue;
			}
			if (i & 1)
				sum += positive[i] * positive[i - 1];
		}

		if (positive.size() & 1)
			sum += positive[positive.size() - 1];

		for (int i = 0; i < negative.size(); i++)
			if (i & 1) 
				sum += negative[i] * negative[i - 1];

		if (negative.size() & 1)
			sum += negative[negative.size() - 1];
	}
	else {
		if (nums[0] < 0)
			sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size(); i++) {
			if (i & 1 && (nums[i] == 1 || nums[i - 1] == 1)) {
				sum += nums[i] + nums[i - 1];
				continue;
			}

			if (i & 1)
				sum += nums[i] * nums[i - 1];
		}

		if (nums.size() & 1)
			sum += nums[nums.size() - 1];
	}
	cout << sum << endl;
}
