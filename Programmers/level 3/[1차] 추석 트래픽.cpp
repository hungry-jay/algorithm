// 그냥 O(n^2)로 (2000 * 2000) 가능했던 문제. -> 이 마저도 "timeout: 3초"을 이용해 단축 가능
// 투포인터로 접근했을 때의 문제점을 너무 늦게 파악

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getDate(string date) {
    string hour;
    string min;
    string sec;
    string ms;
    hour += date[0]; hour += date[1];
    min += date[3]; min += date[4];
    sec += date[6]; sec += date[7];
    ms += date[9]; ms += date[10]; ms += date[11];
    return stoi(ms) + 1000 * stoi(sec) + 1000 * 60 * stoi(min) + 1000 * 60 * 60 * stoi(hour);
}

int getTime(string time) {
    int sec = (time[0] - '0') * 1000;
    string ms;
    for(int i = 2; i < time.length(); i++) {
        if(isdigit(time[i])) {
            ms += time[i];
        }
    }
    
    while(ms.length() < 3) {
        ms += "0";
    }
    return sec + stoi(ms);
}

pair<int, int> lineToProcess(string dateS, string timeS) {
    int date = getDate(dateS);
    int time = getTime(timeS); 
    
    return make_pair(time, date);
}

vector<pair<int, int>> parseToProcess(vector<string> lines) {
    vector<pair<int, int>> parsed;
    
    for(int i = 0; i < lines.size(); i++) {
        string token;
        int pos;
        
        while((pos = lines[i].find(' ')) != string::npos) {
            token = lines[i].substr(0, pos);
            lines[i].erase(0, pos + 1);
        }
        
        pair<int, int> process = lineToProcess(token, lines[i]);
        process.first = process.second - process.first + 1;
        
        parsed.push_back(process);
    }
    
    return parsed;
}

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int solution(vector<string> lines) {
    int answer = 0;
    vector<pair<int, int>> process = parseToProcess(lines);
    
    for(int i = 0; i < process.size(); i++) {
        int subSum = 0;
        for(int j = i; j < process.size(); j++) {
            if(process[j].first <= process[i].second + 999) {
                subSum++;
            }
        }
        if(answer < subSum) {
            answer = subSum;
        }
    }

//     투 포인터 구현 부분
//     for(int lo = 0, hi = 0; hi < process.size(); ) {
//         // left ++
//         if(process[lo].second + 999 < process[hi].first) {
//             lo++;
//         }
        
//         // right ++
//         else if(process[hi].first <= process[lo].second + 999) {
//             hi++;
//         }
        
//         if(answer < hi - lo) {
//             answer = hi - lo;
//         }
//     }
    
    return answer;
}
