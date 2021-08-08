#include <vector>
#include <iostream>

using namespace std;

void doPreorder(vector<vector<char>> v, char cur) {
    int idx = cur - 'A';
    if(cur == '.')
        return;

    cout << cur;
    doPreorder(v, v[idx][0]);
    doPreorder(v, v[idx][1]);
}

void doInorder(vector<vector<char>> v, char cur) {
    int idx = cur - 'A';
    if(cur == '.')
        return;

    doInorder(v, v[idx][0]);
    cout << cur;
    doInorder(v, v[idx][1]);
}

void doPostorder(vector<vector<char>> v, char cur) {
    int idx = cur - 'A';
    if(cur == '.')
        return;

    doPostorder(v, v[idx][0]);
    doPostorder(v, v[idx][1]);
    cout << cur;
}

int main() {
    vector<vector<char>> v;
    int n;
    char tmp;
    cin >> n;
    v.resize(26);
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        int idx = tmp - 'A';
        for(int j = 0 ; j < 2; j++) {
            cin >> tmp;
            v[idx].push_back(tmp);
        }
    }

    doPreorder(v, 'A');
    cout << endl;
    doInorder(v, 'A');
    cout << endl;
    doPostorder(v, 'A');
    cout << endl;

    return 0;
}
