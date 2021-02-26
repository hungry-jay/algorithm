#include <iostream>
#include <queue>
#include <functional>

using namespace std;
/* 
	슬라이딩 윈도우
	일정한 범위를 갖고, 그 범위를 이동하며 확인
	O(n) 선형시간
*/

int n;
priority_queue<int, vector<int>, greater<int>> PQ;

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int tmp;
		for (int j = 0; j < n; j++) {
			scanf("%d", &tmp);
			PQ.push(tmp);
			if(i != 0)
				PQ.pop();
		}
	}

	printf("%d\n", PQ.top());
	return 0;
}
