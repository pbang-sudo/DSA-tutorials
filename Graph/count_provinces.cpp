#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adjList[], int vis[]) {
	vis[node] = 1;
	for (auto it : adjList[node]) {
		if (!vis[it]) {
			dfs(it, adjList, vis);
		}
	}
}

int numProvinces(vector<vector<int>> adj, int V) {
	// code here
	vector<int> adjList[V];
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if (adj[i][j] == 1 && i != j) {
				adjList[i].push_back(j);
				adjList[j].push_back(i);
			}
		}
	}

	int vis[V] = {0};
	int count = 0;
	for (int i = 0; i < V; i++) {
		if (!vis[i]) {
			count++;
			dfs(i, adjList, vis);
		}
	}
	return count;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int V, x;
	cin >> V;
	vector<vector<int>> adj;
	for (int i = 0; i < V; i++) {
		vector<int> temp;
		for (int j = 0; j < V; j++) {
			cin >> x;
			temp.push_back(x);
		}
		adj.push_back(temp);
	}

	cout << numProvinces(adj, V);
	return 0;
}