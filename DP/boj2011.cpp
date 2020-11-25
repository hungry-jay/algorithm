#include <iostream>
#include <string>
#include <vector>

// 여러 case를 잘 나눠야했고 은근히 까다로웠던 문제

using namespace std;

#define MOD 1000000
int dp[5005] = { 0, };

int main(void) {
	string s;
	cin >> s;
	if (s[0] == '0') {
		cout << "0" << endl;
		return 0;
	}
	s = " " + s;
	dp[0] = 1; dp[1] = 1;

	for (int i = 2; i < s.length(); i++) {
		if (s[i] == '0' && !(s[i - 1] == '1' || s[i - 1] == '2')) { // 예외
			cout << "0" << endl;
			return 0;
		}

		int tmp = 10 * (s[i - 1] - '0') + (s[i] - '0');
		if (s[i - 1] == '0' || tmp > 26) { // case 1 
			dp[i] = dp[i - 1];
			continue;
		}
		else if (s[i] == '0') { // case 2
			dp[i] = dp[i - 2];
			continue;
		}
		else { // case 3
			dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
		}

	}
	
	/*for (int i = 1; i < s.length(); i++)
		cout << dp[i] << " ";*/
	cout << dp[s.length() - 1] << endl;
	return 0;
}
