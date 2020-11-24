#include <iostream>

using namespace std;

char stars[7000][7000];

void recursive(int y, int x, int k) {
	if (k == 1) {
		stars[y][x] = '*';
		stars[y + 1][x - 1] = '*'; stars[y + 1][x + 1] = '*';
		for (int j = x - 2; j <= x + 2; j++)
			stars[y + 2][j] = '*';
		return;
	}

	int scale = (k / 2) * 3;
	recursive(y, x, k / 2);
	recursive(y + scale, x - scale, k / 2);
	recursive(y + scale, x + scale, k / 2);

}

int main(void) {
	int n;
	cin >> n;
	int depth = n / 3;
	
	recursive(0, n - 1, depth);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n * 2; j++) {
			if (stars[i][j] == '*')
				cout << stars[i][j];
			else
				cout << " ";
		}
		cout << endl;
	}
}
