#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;
#define INF 987654321

int v, e, k, u, o, w;
vector<vector<pair<int, int>>> adj;
vector<int> d;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;

void dijkstra(int start) {
	PQ.push(make_pair(0, start));
	d[start] = 0;
	while (!PQ.empty()) {
		int cur = PQ.top().second;
		int dist = PQ.top().first;
		PQ.pop();

		if (d[cur] < dist) continue;
		for (int i = 0; i < adj[cur].size(); i++) {
			int next = adj[cur][i].second;
			int nextDist = adj[cur][i].first;

			if (nextDist + dist < d[next]) {
				d[next] = nextDist + dist;
				PQ.push(make_pair(nextDist + dist, next));
			}
		}
	}
}

int main(void) {
	cin >> v >> e;
	cin >> k;
	adj.resize(v + 1);
	d.resize(v + 1);
	for (int i = 1; i <= v; i++)
		d[i] = INF;
	for (int i = 0; i < e; i++) {
		cin >> u >> o >> w;
		adj[u].push_back(make_pair(w, o));
	}
	dijkstra(k);

	for (int i = 1; i <= v; i++) {
		if (d[i] != INF)
			cout << d[i] << "\n";
		else
			cout << "INF\n";
	}
}
