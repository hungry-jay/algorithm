
#include <iostream>
#include <map>

using namespace std;

map <string, int> makeMap() {
    int n;
    cin >> n;
    string dummy, key;
    map <string, int> M;
    for(int i = 0; i < n; i++) {
        cin >> dummy >> key;
        M[key]++;
    }
    return M;
}

int main()
{
    int T, n;
    cin >> T;
    while (T--) {
        map <string, int> M = makeMap();
        int answer = 1;
        for(auto iter = M.begin(); iter != M.end(); iter++){
            answer *= (iter->second + 1);
        }
        cout << answer - 1<< endl;
    }
}
