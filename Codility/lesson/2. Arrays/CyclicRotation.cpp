// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <queue>

deque<int> vectorToDeque(vector<int> A){
    deque<int> DQ;
    for(unsigned int i = 0; i < A.size(); i++){
        DQ.push_back(A[i]);
    }
    return DQ;
}

vector<int> dequeToVector(deque<int> DQ){
    vector<int> V;
    while(!DQ.empty()){
        V.push_back(DQ.front());
        DQ.pop_front();
    }
    return V;
}

void rotate(deque<int> &DQ) {
    int back = DQ.back();
    DQ.pop_back();
    DQ.push_front(back);
}

vector<int> solution(vector<int> &A, int K) {
    if(!A.size() || !K) return A;
    deque<int> DQ = vectorToDeque(A);
    for(int i = 0; i < K; i++) {
        rotate(DQ);
    }
    return dequeToVector(DQ);
}
