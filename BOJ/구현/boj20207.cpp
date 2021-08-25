#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> getDepth(vector<pair<int, int>> plans) {
    vector<int> planOnDay(400, 0);
    for(int i = 0; i < plans.size(); i++) {
        for(int j = plans[i].first; j <= plans[i].second; j++) {
            planOnDay[j]++;
        }
    }
    return planOnDay;
}

int getArea(vector<int> depth) {
    int maxDepth = 0, width = 0, area = 0;

    for(int i = 1; i <= 366; i++) {
        if(depth[i] == 0) {
            area += width * maxDepth;
            width = 0;
            maxDepth = 0;
            continue;
        }

        if(maxDepth < depth[i]) {
            maxDepth = depth[i];
        }
        width++;
    }

    return area;
}

int main(void) {
    int n;
    cin >> n;

    vector<pair<int, int>> plan;
    for(int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        plan.push_back(make_pair(start, end));
    }

    vector<int> depth = getDepth(plan);

    int area = getArea(depth);

    cout << area << endl;
    return 0;
}
