#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, double> a, pair<int, double> b) {
    if(a.second != b.second) return a.second > b.second;
    return a.first < b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double>> failures;
    sort(stages.begin(), stages.end());
    
    int numberOfPlayers = stages.size();
    int idx = 0;
    
    for(int i = 0; i < N; i++) {
        int cnt = 0;
        while(idx != stages.size() && stages[idx] == i + 1) {
            idx++;
            cnt++;
        }
        
        double failure = numberOfPlayers == 0 ? 0 : double(cnt) / numberOfPlayers;
        failures.push_back(make_pair(i + 1, failure));
        numberOfPlayers -= cnt;
    }
    
    sort(failures.begin(), failures.end(), compare);
    
    for(int i = 0; i < N; i++) answer.push_back(failures[i].first);
    return answer;
}
