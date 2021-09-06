#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char words[] = { 'A', 'E', 'I', 'O', 'U' };
vector<string> dict;

void init(int depth, string cur) {
    if(depth == 5) {
        dict.push_back(cur);
        return;
    }

    init(depth + 1, cur);
    for(int i = 0; i < 5; i++) {
        string tmp = cur;
        tmp += words[i];
        init(depth + 1, tmp);
    }
}

int solution(string word) {
    init(0, "");

    sort(dict.begin(), dict.end());
    dict.erase(unique(dict.begin(), dict.end()), dict.end());
    for(int i = 0; i < dict.size(); i++) {
        if(word == dict[i])
            return i;
    }
}
