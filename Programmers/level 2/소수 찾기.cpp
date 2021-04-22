#include <string>
#include <cstring>
#include <map>

#define MAX 10000000

using namespace std;

bool primeNumber[MAX];

void initPrimeNumber() {
    memset(primeNumber, true, sizeof(primeNumber));
    primeNumber[1] = false;
    for(int i = 2; i < MAX; i++)
        for(int j = 2; i * j < MAX; j++)
            primeNumber[i * j] = false;
}

int solution(string numbers) {
    int answer = 0;
    string s;
    map<int, int> m, tmp;
    initPrimeNumber();
    for(int i = 0; i < numbers.length(); i++)
        m[numbers[i] - '0']++;
    
    for(int i = 2; i < MAX; i++) {
        if(primeNumber[i]) {
            tmp.clear();
            s = to_string(i);
            for(int j = 0; j < s.length(); j++)
                tmp[s[j] - '0']++;
            
            bool flag = true;
            for(auto iter = tmp.begin(); iter != tmp.end(); iter++) 
                if(m[iter->first] < iter->second)
                    flag = false;
            
            if(flag)
                answer++;
        }
    }
    
    return answer;
}
