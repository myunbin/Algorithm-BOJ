#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define ppb(x, y) push_back({x, y})
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 1e5 + 1;
int n, ans;
vector<int> adj[MAX_N], child[MAX_N];
bool visited[MAX_N];

void dfs(int cur) {
	visited[cur] = true;
	for (int nxt : adj[cur]) {
		if (visited[nxt]) continue;
		child[cur].pb(nxt);
		dfs(nxt);
	}	
}

void solve(int cur) {
	visited[cur] = true;
	int c = child[cur].size() + 1;
	int lc = (int)ceil(log2(c));

	ans += lc;

	for (int nxt : child[cur]) {
		if (visited[nxt]) continue;
		solve(nxt);
	}
}

int main() {
	fio();
	
	cin >> n;
	adj.resize(n + 1), child.resize(n + 1);

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v), adj[v].pb(u);
	}
	
	dfs(1);
	fill(visited, visited + MAX_N, false);

	ans = n - 1;
	solve(1);

	cout << ans << '\n';

	return 0;
}
