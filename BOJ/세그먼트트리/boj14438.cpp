#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 100000
#define INF 2000000000

int n, m;
vector<int> nums;
int tree[MAX * 4] = { 0, };

/* 세그먼트 트리 문제.

   update 함수 구현 삽질.. 
	-> nums 업데이트하고 트리 업데이트하면서 min값 찾아줘야하는데 그냥 += diff로 해버렸다.
	출력 초과 -> 사실상 틀렸습니다 였음
*/

int init(int start, int end, int node) {
	if (start == end)
		return tree[node] = nums[start];
	
	int mid = start + (end - start) / 2;
	return tree[node] = min(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}


int update(int start, int end, int node, int idx, int diff) {
	if (idx < start || end < idx)
		return tree[node];
	
	if (start == end) {
		return tree[node] = diff;
	}
	
	int mid = start + (end - start) / 2;

	return tree[node] = min(update(start, mid, node * 2, idx, diff), update(mid + 1, end, node * 2 + 1, idx, diff));
}


int getMin(int start, int end, int node, int left, int right) {
	if (end < left || right < start)
		return INF;

	if (left <= start && end <= right)
		return tree[node];

	int mid = start + (end - start) / 2;
	return min(getMin(start, mid, node * 2, left, right), getMin(mid + 1, end, node * 2 + 1, left, right));
}


int main(void) {
	cin.tie(NULL);
	cin >> n;
	nums.resize(n);
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	cin >> m;
	int len = nums.size();
	init(0, len - 1, 1);

	while (m-- > 0) {
		int q, i, j;
		cin >> q >> i >> j;
		if (q == 1) {
			update(0, len - 1, 1, i - 1, j);
			nums[i - 1] = j;
		}
		else if (q == 2) {
			int ret = getMin(0, len - 1, 1, i - 1, j - 1);
			cout << ret << "\n";
		}

	}
	return 0;
}
