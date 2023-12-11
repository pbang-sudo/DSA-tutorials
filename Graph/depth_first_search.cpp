#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &ans, bool vis[]) {
	vis[node] = true;
	ans.push_back(node);
	for (auto it : adj[node]) {
		if (!vis[it]) {
			dfs(it, adj, ans, vis);
		}
	}
}

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
	bool vis[V] = {false};
	vector<int> ans;
	dfs(0, adj, ans, vis);
	return ans;
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

	vector<int> bfs = dfsOfGraph(V, adj);
	for (unsigned int i = 0; i < bfs.size(); i++)
		cout << bfs[i] << " ";
	return 0;
}