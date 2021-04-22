#include <string>
#include <vector>

using namespace std;

void solve(vector<int> numbers, int depth, int sum, int target, int &answer) {
    if(depth == numbers.size()) {
        if(target == sum)
            answer++;
        return;
    }
    
    solve(numbers, depth + 1, sum + numbers[depth], target, answer);
    solve(numbers, depth + 1, sum - numbers[depth], target, answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    solve(numbers, 0, 0, target, answer);
    return answer;
}
