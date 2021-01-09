#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2e5 + 1;
int n, q;
int p[MAX_N], anc[MAX_N];
vector<int> adj[MAX_N], cycle;
int comp[MAX_N];
bool visited[MAX_N], inCycle[MAX_N];

int find(int a) {
	return p[a] = p[a] == a ? a : find(p[a]);
}

bool merge(int a, int b) {
	a = find(a); b = find(b);
	if (a == b) return false;
	p[a] = b;
	return true;
}

void track(int u, int c) {
	inCycle[c] = true;
	cycle.push_back(c);
	if (u == c) return;
	track(u, anc[c]);
}

void dfs(int c, int u, int v) {
	if (c == v) track(u, v);
	visited[c] = true;
	for (int nxt : adj[c]) {
		if (visited[nxt]) continue;
		anc[nxt] = c;
		dfs(nxt, u, v);
	}
}

void dfs2(int s, int c) {
	comp[c] = s;
	visited[c] = true;
	for (int nxt : adj[c]) {
		if (inCycle[nxt] || visited[nxt]) continue;
		dfs2(s, nxt);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);
	
	cin >> n >> q;
	for(int i = 0; i <= n; i++) p[i] = i;
	
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		if(!merge(u, v)) dfs(u, u, v);
	}
	
	fill(visited, visited + MAX_N, false);
	for (int x : cycle) dfs2(x, x);
	
	while (q--) {
		int a, b;
		cin >> a >> b;
		a = comp[a]; b = comp[b];
		if (a == b) cout << 1 << '\n';
		else cout << 2 << '\n';
	}
	
	return 0;
}
