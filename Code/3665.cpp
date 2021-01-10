#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
using namespace std;
const int MAX_N = 505;
int main() {
	fio();
		
	int t; cin >> t;
	while (t--) {
		int n, m, a[MAX_N], ind[MAX_N] = { 0 };
		vector<int> adj[MAX_N];
		
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			ind[a[i]] = i - 1;
		}
		
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) 
				adj[a[i]].pb(a[j]);
		}
	
		cin >> m;
		while (m--) {
			int u, v; 
			cin >> u >> v;
			
			int a = -1, b = -1, idx = -1;
			for (int i = 0; i < adj[u].size(); i++) {
				if (adj[u][i] == v) {
					idx = i;
					a = u; b = v;
					break;
				}
			}
			if (a == -1 && b == -1) {
				for (int i = 0; i < adj[v].size(); i++) {
					if (adj[v][i] == u) {
						idx = i;
						a = v; b = u;
						break;
					}
				}
			}
			ind[b]--; ind[a]++;
			adj[a].erase(adj[a].begin() + idx);
			adj[b].pb(a);
		}
		
		queue<int> q;
		for (int i = 1; i <= n; i++) 
			if (ind[i] == 0) q.push(i);
		
		vector<int> ans;
		while (!q.empty()) {
			if (q.size() > 1) {
				cout << '?' << '\n';
				break;
			}
			int c = q.front(); q.pop();
			ans.pb(c);
			
			for (int nxt : adj[c]) {
				if (!--ind[nxt]) q.push(nxt);
			}
		}
		
		bool cycle = false;
		for (int i = 1; i <= n; i++) {
			if (ind[i]) {
				cycle = true; 
				break;
			}
		}
		
		if (cycle) cout << "IMPOSSIBLE";
		else for (int x : ans) cout << x << ' ';
		cout << '\n';
	}
	return 0;
}
