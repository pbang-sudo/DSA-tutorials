#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
	bool vis[V] = {false};
	queue<int> q;
	vis[0] = 1;
	q.push(0);
	vector<int> bfs;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		bfs.push_back(node);

		for (auto it : adj[node]) {
			if (!vis[it]) {
				vis[it] = 1;
				q.push(it);
			}
		}
	}
	return bfs;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int V, E;
	cin >> V >> E;
	vector<int> adj[V + 1];
	for (int i = 0; i < E; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}

	vector<int> bfs = bfsOfGraph(V, adj);
	for (unsigned int i = 0; i < bfs.size(); i++)
		cout << bfs[i] << " ";
	return 0;
}