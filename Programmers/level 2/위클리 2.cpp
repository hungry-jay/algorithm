// 코테인가 어디서 분명 풀었던문제

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<vector<int>> scores) {
    string answer = "";
    
    for(int i = 0; i < scores.size(); i++) {
        int subMax = -1;
        int subMin = 101;
        int subSum = 0;
        
        for(int j = 0; j < scores.size(); j++) {
            int cur = scores[j][i];
            if(cur > subMax) subMax = cur;
            if(cur < subMin) subMin = cur;
        }
        
        bool isOnlySubMax = true;
        bool isOnlySubMin = true;
        
        for(int j = 0; j < scores.size(); j++) {
            int cur = scores[j][i];
            if(i != j && cur == subMax)
                isOnlySubMax = false;
            if(i != j && cur == subMin)
                isOnlySubMin = false;
        }
        
        int byDivide = isOnlySubMax || isOnlySubMin ? scores.size() - 1 : scores.size();
        
        for(int j = 0; j < scores.size(); j++) {
            int cur = scores[j][i];
            if((isOnlySubMax || isOnlySubMin) && i == j)
                continue;
            subSum += cur;
        }
        
        double subScore = (double)subSum / byDivide;
        
        if(subScore >= 90) answer += 'A';
        else if(subScore >= 80) answer += 'B';
        else if(subScore >= 70) answer += 'C';
        else if(subScore >= 50) answer += 'D';
        else answer += 'F';
    }
    
    return answer;
}
