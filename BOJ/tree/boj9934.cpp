#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> answer;
int k;

void getAnswer(vector<int> v, int idx, int cur, int depth) {
    if(depth == k)
        return;

    int interval = 1;
    for(int i = 0; i < k - depth - 2; i++)
        interval *= 2;

    answer[depth].push_back(cur);
    int left = idx - interval;
    int right = idx + interval;
    getAnswer(v, left, v[left], depth + 1);
    getAnswer(v, right, v[right], depth + 1);
}

int main(void) {
    int n = 1;
    cin >> k;
    answer.resize(k);
    vector<int> v;
    for(int i = 0; i < k; i++) n *= 2;

    int mid = n / 2 - 1;
    n--;

    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    getAnswer(v, mid, v[mid], 0);

    for(int i = 0; i < k; i++) {
        for(int j : answer[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
