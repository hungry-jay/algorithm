
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;
vector<int> parents;

void go(int cur) {
    for(int i = 0; i < tree[cur].size(); i++) {
        int next = tree[cur][i];
        if(!parents[next]) {
            parents[next] = cur;
            go(next);
        }
    }
}

int main()
{
    int n, from, to;
    scanf("%d", &n);
    tree.resize(n + 1);
    parents.resize(n + 1, 0);
    for(int i = 0; i < n - 1; i++) {
        scanf("%d %d", &from, &to);
        tree[to].push_back(from);
        tree[from].push_back(to);
    }

    parents[1] = 1;
    go(1);

    for(int i = 2; i <= n; i++)
        printf("%d\n", parents[i]);

    return 0;
}
