#include <string>
#include <vector>
#include <set>

using namespace std;

int ranking[] = { 6, 6, 5, 4, 3, 2, 1 };

set<int> initNumberSet(vector<int> lottos, int & numberOfZero) {
    set<int> myNums;
    for(int i = 0; i < lottos.size(); i++) {
        if(lottos[i])
            myNums.insert(lottos[i]);
        else
            numberOfZero++;
    }
    return myNums;
}

int getWinningNumber(vector<int> win_nums, set<int> myNums) {
    int winning = 0;
    for(int i = 0; i < win_nums.size(); i++)
        if(myNums.find(win_nums[i]) != myNums.end())
            winning++;
    return winning;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    int numberOfZero = 0;
    set<int> myNums = initNumberSet(lottos, numberOfZero);
    
    int winning = getWinningNumber(win_nums, myNums);
    
    vector<int> answer;
    answer.push_back(ranking[winning + numberOfZero]);
    answer.push_back(ranking[winning]);
    
    return answer;
}
