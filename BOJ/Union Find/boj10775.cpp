#include <iostream>

using namespace std;

/* union find 알고리즘. 자기 자신을 가리키면 root임.
	핵심은 재귀를 통해 부모의 부모(가장 첫 root)를 가리키도록 갱신한다.

	처음에 갱신하는 부분이 이해가 잘 안됐었는데 생각보다 간단한거같다?
	재귀부분을 다시 한번 살펴봐야 할 듯하다.
*/

#define MAX 100001

int g, p;
int parent[MAX];

int getParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

void unionParent(int x, int y) {
	x = getParent(x);
	y = getParent(y);
	if (x < y) parent[y] = x;
	else parent[x] = y;
}

int main(void) {
	cin >> g >> p;
	for (int i = 0; i <= g; i++)
		parent[i] = i;
	
	int answer = 0;
	for (int i = 0; i < p; i++) {
		int cur;
		cin >> cur;
		cur = getParent(cur);

		if (cur == 0) 
			break;

		unionParent(cur, cur - 1);

		answer++;
	}

	cout << answer << endl;

	return 0;
}
