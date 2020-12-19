#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e6 + 1;
const int INF = 2e9;
int n;
bool check[MAX_N];
vector<int> adj[MAX_N];
vector<int> child[MAX_N];

void dfs(int cur) {
	check[cur] = true;
	for (int nxt : adj[cur]) {
		if (!check[nxt]) {
			child[cur].push_back(nxt);
			dfs(nxt);
		}
	}
}

int dp[MAX_N][2];

int go(int node, bool parent) {
	int &ret = dp[node][parent];
	if (ret != -1) return ret;
	
	int temp1 = INF, temp2 = 1;
	
	for (int nxt : child[node]) {
		temp2 += go(nxt, true);
	}	
	
	if (parent) {
		temp1 = 0;
		for (int nxt : child[node])
			temp1 += go(nxt, false);
	}
	
	return ret = min(temp1, temp2);
}

int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);
	
	memset(dp, -1, sizeof(dp));
	
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs(1);
	
	cout << go(1, true) << '\n';

	return 0;
}
