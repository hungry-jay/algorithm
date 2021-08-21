#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    vector<string> pad;
    
    pad.push_back("123");
    pad.push_back("456");
    pad.push_back("789");
    pad.push_back("*0#");
    
    pair<int, int> curLeft = make_pair(3, 0);
    pair<int, int> curRight = make_pair(3, 2);
    
    for(int i = 0; i < numbers.size(); i++) {
        int num = numbers[i];
        if(num % 3 == 1) {
            answer += "L";
            int idx;
            if(num == 1) idx = 0;
            if(num == 4) idx = 1;
            if(num == 7) idx = 2;
            curLeft = make_pair(idx, 0);
        }
        else if(num % 3 == 0 && num != 0) {
            answer += "R";
            int idx;
            if(num == 3) idx = 0;
            if(num == 6) idx = 1;
            if(num == 9) idx = 2;
            curRight = make_pair(idx, 2);
        }
        else {
            pair<int, int> cur;    
            int idx;
            
            if(num == 2) {
                cur = make_pair(0, 1);
                idx = 0;
            }
            if(num == 5) {
                cur = make_pair(1, 1);
                idx = 1;
            }
            if(num == 8) {
                cur = make_pair(2, 1);
                idx = 2;
            }
            if(num == 0) {
                cur = make_pair(3, 1);
                idx = 3;
            }
            
            int leftDist = abs(cur.first - curLeft.first) + abs(cur.second - curLeft.second);
            int rightDist = abs(cur.first - curRight.first) + abs(cur.second - curRight.second);
            
            if(leftDist < rightDist) {
                answer += "L";
                curLeft = make_pair(idx, 1);
            }
            
            else if(leftDist > rightDist) {
                answer += "R";
                curRight = make_pair(idx, 1);
            }
            
            else {
                if(hand == "left") {
                    answer += "L";
                    curLeft = make_pair(idx, 1);
                }
                else {
                    answer += "R";
                    curRight = make_pair(idx, 1);
                }
            }
        }
    }
    
    return answer;
}
