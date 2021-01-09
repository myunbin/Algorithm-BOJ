#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
using namespace std;
const int MAX_N = 1e5 + 1;
bool v[MAX_N], f[MAX_N];
int p[MAX_N], ans;
vector<int> adj[MAX_N];

void track(int c, int e) {
	ans++;
	if (c == e) return;
	track(p[c], e);
}

void dfs(int cur) {
	v[cur] = true;
	for (int nxt : adj[cur]) {
		if (!v[nxt]) {
			p[nxt] = cur;
			dfs(nxt);
		}
		else if (!f[nxt]) track(cur, nxt); 
	}
	f[cur] = true;
}

int main() {
	fio();

	int t; 
	cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) {
			int x; cin >> x;
			adj[i].pb(x);
		}
		for (int i = 1; i <= n; i++) {
			if (!v[i]) dfs(i);
		}
		cout << n - ans << '\n';
		
		ans = 0; 
		for (int i = 1; i <= n; i++) adj[i].clear();
		memset(v, 0, sizeof(v));
		memset(f, 0, sizeof(f));
	}
	
	return 0;
}
