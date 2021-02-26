// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(int N, vector<int> &A) {
    vector<int> counters(N);
    int currentMax = 0, update = 0,current = 0;

    for(unsigned int i = 0; i < A.size(); i++){
        current = A[i];
        if(current == N + 1){
            update = currentMax;
            continue;
        }

        counters[current - 1] = 
            counters[current - 1] < update ? update + 1 :  counters[current - 1] + 1;

        if(counters[current - 1] > currentMax)
            currentMax = counters[current - 1];
    }

    for(unsigned int i = 0; i < counters.size(); i++){
        if(counters[i] < update)
            counters[i] = update;
    }

    return counters;
}
