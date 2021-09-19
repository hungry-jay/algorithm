#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct BoxerInfos {
    int num;
    double winRate;
    int winningHeavier = 0;
    int weight;
};

vector<BoxerInfos> initBoxerInfos(vector<int> weights, vector<string> head2head) {
    vector<BoxerInfos> infos;
    for(int i = 0; i < head2head.size(); i++) {
        BoxerInfos info{};
        int won = 0, losed = 0;
        string cur = head2head[i];
        int myWeight = weights[i];
        info.num = i + 1;
        info.weight = myWeight;
        for(int j = 0; j < cur.length(); j++) {
            if(i == j) continue;

            if(cur[j] == 'W') {
                won++;
                if(myWeight < weights[j]) info.winningHeavier++;
            }
            else if(cur[j] == 'L') losed++;
        }

        info.winRate = won + losed != 0 ? (double) won / (won + losed) : 0;
        infos.push_back(info);
    }

    return infos;
}

bool compare(BoxerInfos a, BoxerInfos b) {
    if(a.winRate != b.winRate) return a.winRate > b.winRate;
    else if(a.winningHeavier != b.winningHeavier) return a.winningHeavier > b.winningHeavier;
    else if(a.weight != b.weight) return a.weight > b.weight;
}

vector<int> solution(vector<int> weights, vector<string> head2head) {
    vector<int> answer;
    vector<BoxerInfos> infos = initBoxerInfos(std::move(weights), std::move(head2head));

    stable_sort(infos.begin(), infos.end(), compare);
    for(auto & info : infos) {
        answer.push_back(info.num);
    }
    return answer;
}
