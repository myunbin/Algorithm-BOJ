#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 1;
int n;
vector<int> adj[MAX_N];
vector<int> child[MAX_N];
int w[MAX_N];
bool v[MAX_N];

void dfs(int cur) {
	v[cur] = true;
	for (int nxt : adj[cur]) {
		if (!v[nxt]) {
			child[cur].push_back(nxt);
			dfs(nxt);
		}
	}
}

int dp[MAX_N][2];

int go(int node, bool parent) {
	int &ret = dp[node][parent];
	if (ret != -1) return ret;
	
	int tmp1 = 0;
	for (int nxt : child[node]) 
		tmp1 += go(nxt, false);
	
	int tmp2 = -1;
	if (!parent) {
		tmp2 = w[node];
		for (int nxt : child[node]) 
			tmp2 += go(nxt, true);
	}
	
	return ret = max(tmp1, tmp2);
}
int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);
	
	memset(dp, -1, sizeof(dp));
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> w[i];	
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs(1);
	
	cout << go(1, false) << '\n';
	return 0;
}
