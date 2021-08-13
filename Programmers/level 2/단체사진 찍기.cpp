#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool satisfiesCondition(vector<char> friends, char a, char b, char oper, int required) {
    int dist = -1;
    bool isFirst = true;
    
    for(int i = 0; i < friends.size(); i++) {
        char cur = friends[i];
        
        if((cur == a || cur == b) && isFirst) {
            isFirst = false;
            continue;
        }
        
        if(isFirst) continue;

        dist++;
        if(cur == a || cur == b) break;
    }
    
    if(oper == '>') return dist > required ? true : false;
    else if(oper == '=') return dist == required ? true : false;
    else if(oper == '<') return dist < required ? true : false;
}

bool satisfiesAllConditions(vector<char> friends, vector<string> data) {
    for(int i = 0; i < data.size(); i++) {
        string cur = data[i];
        char a = cur[0];
        char b = cur[2];
        char oper = cur[3];
        int required = cur[4] - '0';
        
        if(!satisfiesCondition(friends, a, b, oper, required)) return false;
    }
    return true;
}

int solution(int n, vector<string> data) {
    vector<char> friends = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };
    int answer = 0;
    
    do {
        if(satisfiesAllConditions(friends, data)) answer++;
    } while(next_permutation(friends.begin(), friends.end()));
    
    return answer;
}
