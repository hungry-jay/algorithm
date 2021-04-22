#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    stack<pair<int, int>> S;
    
    for(int i = 0; i < prices.size(); i++) {
        int cur = prices[i];
        while(!S.empty() && cur < S.top().first) {
            answer[S.top().second] = i - S.top().second;
            S.pop();
        }
        S.push(make_pair(cur, i));
    }
    
    for(int i = 0; i < answer.size(); i++)
        if(!answer[i])
            answer[i] = answer.size() - i - 1;
    
    return answer;
}
