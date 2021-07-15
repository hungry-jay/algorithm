#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    string words[] = { "ze", "on", "tw", "th", "fo", "fi", "si", "se", "ei", "ni" };
    int len[] = { 4, 3, 3, 5, 4, 4, 3, 5, 5, 4 };
    
    string answer = "";
    int i = 0;
    while(i < s.length()) {
        if(isdigit(s[i])) {
            answer += s[i];
            i++;
        }
        else {
            string tmp = "";
            tmp += s[i];
            tmp += s[i + 1];
            for(int j = 0; j < 10; j++) {
                if(words[j] != tmp)
                    continue;
                answer += j + '0';
                i += len[j];
                break;
            }
        }
    }
    
    return stoi(answer);
}
