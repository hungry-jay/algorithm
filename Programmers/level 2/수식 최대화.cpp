#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long calculate(long long num1, char oper, long long num2) {
    if(oper == '*') return num1 * num2;
    else if(oper == '+') return num1 + num2;
    else return num1 - num2;
}

void parse(string s, vector<long long> &nums, vector<char> &opers) {
    string curNum;
    for(int i = 0; i < s.length(); i++) {
        if(isdigit(s[i])) {
            curNum += s[i];
        }
        else {
            opers.push_back(s[i]);
            nums.push_back(stoll(curNum));
            curNum = "";
        }
    }
    nums.push_back(stoll(curNum));
}

long long getPrize(vector<char> priority, int depth, vector<long long> nums, vector<char> opers) {
    if(depth == 3) {
        return nums[0];
    }
    
    vector<long long> newNums;
    vector<char> newOpers;
    
    char curOper = priority[depth];
    for(int i = 0; i < opers.size(); i++) {
        if(opers[i] != curOper) {
            newNums.push_back(nums[i]);
            newOpers.push_back(opers[i]);
            continue;
        }
        else {
            nums[i + 1] = calculate(nums[i], opers[i], nums[i + 1]);
        }
    }
    
    newNums.push_back(nums[nums.size() - 1]);
    
    return getPrize(priority, depth + 1, newNums, newOpers);
}

long long solution(string expression) {
    long long answer = 0;

    vector<long long> nums;
    vector<char> opers;
    parse(expression, nums, opers);
    vector<char> priority = { '*', '+', '-' };
    
    do {
        long long subAnswer = getPrize(priority, 0, nums, opers);
        subAnswer = subAnswer > 0 ? subAnswer : -subAnswer;
        if(answer < subAnswer) {
            answer = subAnswer;
        }
    } while(next_permutation(priority.begin(), priority.end()));
    
    return answer;
}
