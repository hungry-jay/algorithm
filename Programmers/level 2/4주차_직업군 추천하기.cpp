#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> parse(string s) {
    vector<string> parsed;

    string token;
    int pos = 0;
    while((pos = s.find(' ')) != string::npos) {
        token = s.substr(0, pos);
        s.erase(0, pos + 1);
        parsed.push_back(token);
    }
    parsed.push_back(s);

    return parsed;
}

pair<string, int> getCurScore(string table, vector<string> languages, vector<int> preference) {
    vector<string> parsed;
    parsed = parse(table);
    int sum = 0;
    for(int i = 0; i < languages.size(); i++) {
        for(int j = 1; j < parsed.size(); j++) {
            string cur = parsed[j];
            if(languages[i] == cur) {
                sum += (6 - j) * preference[i];
                break;
            }
        }
    }

    return make_pair(parsed[0], sum);
}

bool compare(pair<string, int> a, pair<string, int> b) {
    if(a.second != b.second) return a.second > b.second;
    return a < b;
}

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    vector<pair<string, int>> scores;
    for(int i = 0 ; i < table.size(); i++) {
        pair<string, int> compAndScore = getCurScore(table[i], languages, preference);
        scores.push_back(compAndScore);
    }
    
    sort(scores.begin(), scores.end(), compare);

    return scores[0].first;
}
