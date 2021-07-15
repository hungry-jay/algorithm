// 하드코딩

#include <string>
#include <vector>

using namespace std;

#define MAX 101

int nums[101][101] = {0, };

void init(int row, int col) {
    int num = 1;
    for(int i = 1; i <= row; i++)
        for(int j = 1; j <= col; j++)
            nums[i][j] = num++;
}

int rotate(int y1, int x1, int y2, int x2) {
    int tmp = nums[y1][x1];
    int answer = tmp;
    
    int i = y1, j = x1;
    for( ; i < y2; i++) {
        nums[i][j] = nums[i + 1][j]; 
        if(nums[i][j] < answer)
            answer = nums[i][j];
    }
    for( ; j < x2; j++) {
        nums[i][j] = nums[i][j + 1];
        if(nums[i][j] < answer)
            answer = nums[i][j];
    }
    for( ; y1 < i; i--) {
        nums[i][j] = nums[i - 1][j];
        if(nums[i][j] < answer)
            answer = nums[i][j];
    }
    for( ; x1 + 1 < j; j--) {
        nums[i][j] = nums[i][j - 1];
        if(nums[i][j] < answer)
            answer = nums[i][j];
    }
    nums[i][j] = tmp;
    
    return answer;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    init(rows, columns);
    
    for(int i = 0; i < queries.size(); i++) {
        vector<int> cur = queries[i];
        answer.push_back(rotate(cur[0], cur[1], cur[2], cur[3]));
    }
    return answer;
}
