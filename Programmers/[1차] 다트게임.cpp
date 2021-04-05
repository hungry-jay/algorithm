#include <string>
#include <iostream>

// 다른사람 풀이 -> sstream library 참고

using namespace std;

int solution(string dartResult) {
    int score = 0, index = -1;
    int scores[3] = {0, };
    
    for(int i = 0; i < dartResult.length(); i++) {
        int cur = dartResult[i];
        
        if(isdigit(cur)) {
            if(index != -1)
                scores[index] = score;
            
            index++;
            
            if(dartResult[i + 1] == '0') {
                score = 10;
                i++;
                continue;
            }
            
            score = cur - '0';
        }
        
        switch(cur) {
            case 'D':
                score = score * score;
                break;
            case 'T':
                score = score * score * score;
                break;
            case '*':
                score *= 2;
                if(index != 0)
                    scores[index - 1] *= 2;
                break;
            case '#':
                score *= -1;
                break;
            default:
                break;
        }
    }
    
    return scores[0] + scores[1] + score;
}
