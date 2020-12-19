#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 1;

vector<int> adj[MAX_N];
vector<int> child[MAX_N];
int n, m[MAX_N];
bool check[MAX_N];

void dfs(int curr) {
	check[curr] = true;
	
	for (int nxt : adj[curr]) {
		if (check[nxt]) continue;
		child[curr].push_back(nxt);
		dfs(nxt);
	}
}

int dp[MAX_N][2];
int go(int curr, bool parent) {
	int &ret = dp[curr][parent];
	if (ret != -1) return ret;
	
	int temp = 0;
	for (int nxt : child[curr]) {
		temp += go(nxt, false);
	}
	
	int temp2 = -1;
	if (!parent) {
		temp2 = m[curr];
		for (int nxt : child[curr]) {
			temp2 += go(nxt, true);
		}
	}
	
	return ret = max(temp, temp2);
}

vector<int> ans;
void trackAns(int curr, bool parent) {
	int temp = 0;
	for (int nxt : child[curr]) {
		temp += go(nxt, false);
	}
	int temp2 = -1;
	if (!parent) {
		temp2 = m[curr];
		for (int nxt : child[curr]) {
			temp2 += go(nxt, true);
		}
	}
	
	if (temp > temp2) {
		for (int nxt : child[curr])
			trackAns(nxt, false);
	}
	else {
		ans.push_back(curr);
		for (int nxt : child[curr])
			trackAns(nxt, true);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);

	memset(dp, -1, sizeof(dp));
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> m[i];
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	cout << go(1, false) << '\n';
	trackAns(1, false);
	
	sort(ans.begin(), ans.end());
	for (int x : ans) cout << x << ' ';
	cout << '\n';
	
	return 0;
}
