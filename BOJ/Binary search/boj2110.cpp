#include <iostream>
#include <algorithm>
#include <vector>

// 간단한 binary search.
// *max_element(시작, 끝), *min_element(시작, 끝) 귀찮은 작업 줄여주기.

using namespace std;

int n, c;
vector<int> house;

bool search(int dist) {
	int prev = house[0];
	int cnt = 1;
	for (int i = 1; i < house.size(); i++) {
		if (house[i] - prev >= dist) {
			cnt++;
			prev = house[i];
		}
	}
	if (cnt < c)
		return false;
	return true;
}

int main(void) {
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		house.push_back(tmp);
	}
	sort(house.begin(), house.end());

	int left = 1;
	int right = *max_element(house.begin(), house.end()) - *min_element(house.begin(), house.end());
	int mid;
	while (left <= right) {
		mid = left + (right - left) / 2;
		if (search(mid))
			left = mid + 1;
		else
			right = mid - 1;
	}

	cout << right << endl;
	return 0;
}
