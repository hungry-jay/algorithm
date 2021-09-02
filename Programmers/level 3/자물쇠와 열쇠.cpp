// 그림 그려서 원소 매칭하기

#include <string>
#include <vector>

using namespace std;

void turnRight(vector<vector<int>> &key) {
    vector<vector<int>> tmp = key;
    int n = key.size() - 1;
    for(int i = 0; i < tmp.size(); i++) {
        for(int j = 0; j < tmp[i].size(); j++) {
            key[j][n - i] = tmp[i][j];
        }
    }
}

vector<vector<int>> padLock(vector<vector<int>> lock, int pad) {
    int length = lock.size();
    vector<vector<int>> newLock;
    vector<int> oneLine(length + 2 * pad, -1);

    for(int i = 0; i < pad; i++) {
        newLock.push_back(oneLine);
    }
    
    for(int i = 0; i < length; i++) {
        vector<int> cur;
        for(int j = 0; j < pad; j++) {
            cur.push_back(-1);
        }
        
        for(int j = 0; j < lock[i].size(); j++) {
            cur.push_back(lock[i][j]);
        }
        
        for(int j = 0; j < pad; j++) {
            cur.push_back(-1);
        }
        newLock.push_back(cur);
    }
    
    for(int i = 0; i < pad; i++) {
        newLock.push_back(oneLine);
    }
    
    return newLock;
}

bool validate(vector<vector<int>> lock) {
    for(int i = 0; i < lock.size(); i++) {
        for(int j = 0; j < lock[i].size(); j++) {
            if(lock[i][j] == 1 || lock[i][j] == -1)
                continue;
            return false;
        }
    }
    return true;
}

bool checkEachCase(vector<vector<int>> key, vector<vector<int>> lock, int y, int x) {
    for(int i = y; i < y + key.size(); i++) {
        for(int j = x; j < x + key.size(); j++) {
            if(lock[i][j] == -1) continue;
            if(lock[i][j] + key[i - y][j - x] == 1) {
                lock[i][j] = 1;
                continue;
            }
            return false;
        }
    }
    return validate(lock) ? true : false;
}

bool rotate(vector<vector<int>> key, vector<vector<int>> lock) {
    int n = lock.size() - key.size();
    
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            if(checkEachCase(key, lock, i, j)) {
                return true;
            }
        }
    }
    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    lock = padLock(lock, key.size() - 1);
    
    if(validate(lock)) return true;
    for(int i = 0; i < 4; i++) {
        if(rotate(key, lock)) {
            return true;
        }
        turnRight(key);
    }
    
    return false;
}
