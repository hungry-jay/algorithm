#include <string>
#include <map>

using namespace std;

map<string, int> makeMap(string s) {
    map<string, int> m;
    for(int i = 0; i < s.length() - 1; i++) {
        if(isalpha(s[i]) && isalpha(s[i + 1])) {
            string cur;
            cur += tolower(s[i]);
            cur += tolower(s[i + 1]);
            m[cur]++;
        }
    }
    return m;
}

int getIntersection(map<string, int> a, map<string, int> b) {
    int num = 0;
    for(auto iter = a.begin(); iter != a.end(); iter++) {
        num += b[iter->first] < iter->second ? b[iter->first] : iter->second;
    }
    
    return num;
}

int getUnion(map<string, int> a, map<string, int> b) {
    int num = 0;
    for(auto iter = a.begin(); iter != a.end(); iter++) {
        num += b[iter->first] > iter->second ? b[iter->first] : iter->second;
        b[iter->first] = 0;
    }
    
    for(auto iter = b.begin(); iter != b.end(); iter++) {
        if(iter->second) {
            num += iter->second;
        }
    }
    
    return num;
}

int solution(string str1, string str2) {
    int answer = 0;
    
    map<string, int> a = makeMap(str1);
    map<string, int> b = makeMap(str2);
    
    int intersectionNum = getIntersection(a, b);
    int unionNum = getUnion(a, b);
    
    return unionNum ? 65536 * (double)intersectionNum / unionNum : 65536;
}
