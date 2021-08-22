#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    stack<int> S;
    for(int i = 0; i < moves.size(); i++) {
        int idx = moves[i] - 1;
        
        for(int j = 0; j < board.size(); j++) {
            int cur = board[j][idx];
            if(cur != 0) {
                board[j][idx] = 0;
                if(!S.empty() && cur == S.top()) {
                    S.pop();
                    answer += 2;
                }
                else {
                    S.push(cur);
                }
                
                break;
            }
        }
    }
        
    return answer;
}
