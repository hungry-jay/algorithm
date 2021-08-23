// 문제를 정확히 파악하기..

#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.length();
    
    for(int len = 1; len <= s.length() / 2; len++) {
        
        int count = 1, subAnswer = 0;
        string tmp = s;
        
        for(int i = 0; i + len * 2 <= tmp.length(); ) {
            string cur;
            string next;
            
            // make cur and next
            for(int j = i; j < i + len; j++) {
                cur += tmp[j];
                next += tmp[j + len];
            }
            
            if(cur == next) {
                tmp.erase(i, len);
                count++;
            }
            else {
                i += len;
                if(count != 1) {
                    subAnswer += to_string(count).length();
                    count = 1;
                }
            }
        }
        
        if(count != 1) {
            subAnswer += to_string(count).length();
        }
        
        subAnswer += tmp.length();
        
        if(subAnswer < answer) {
            answer = subAnswer;
        }
    }
    
    return answer;
}
