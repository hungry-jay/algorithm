// 비트 문제

#include <string>
#include <vector>

using namespace std;

long long getAnswer(long long num) {
    long long checkBit = 1;
    while(checkBit < num) {
        if(!(num & checkBit))
            break;
        checkBit = checkBit << 1;
    }
    
    return checkBit + num - checkBit / 2;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(int i = 0; i < numbers.size(); i++) {
        long long cur = numbers[i];
        answer.push_back(getAnswer(cur));
    }
    return answer;
}
