// stl sort() : 불안정정렬(quick). stable_sort() : 안정정렬(merge sort??)
// parsing edge case 고려

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

pair<string, pair<string, string>> parseFile(string file) {
    string head, number, tail;
    int idx = 0;
    for( ; idx < file.length(); idx++) {
        if(isdigit(file[idx])) {
            break;
        }
        head += file[idx];
    }
    
    for( ; idx < file.length(); idx++) {
        if(number.length() == 5 || !isdigit(file[idx])) {
            break;
        }
        number += file[idx];
    }
    
    tail = file.erase(0, idx);
    
    return make_pair(head, make_pair(number, tail));
}

bool compare(pair<string, pair<string, string>> a, pair<string, pair<string, string>> b) {
    string head_a = a.first;
    string head_b = b.first;
    
    for(int i = 0; i < head_a.length(); i++) {
        head_a[i] = tolower(head_a[i]);
    }
    
    for(int i = 0; i < head_b.length(); i++) {
        head_b[i] = tolower(head_b[i]);
    }
    
    int num_a = stoi(a.second.first);
    int num_b = stoi(b.second.first);
    
    if(head_a != head_b) {
        return head_a < head_b;
    }
    return num_a < num_b;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<pair<string, pair<string, string>>> parsed;
    
    for(int i = 0; i < files.size(); i++) {
        pair<string, pair<string, string>> cur = parseFile(files[i]);
        parsed.push_back(cur);
    }
    
    stable_sort(parsed.begin(), parsed.end(), compare);
    
    for(int i = 0; i < parsed.size(); i++) {
        string cur;
        cur += parsed[i].first;
        cur += parsed[i].second.first;
        cur += parsed[i].second.second;
        answer.push_back(cur);
    }
    
    return answer;
}
