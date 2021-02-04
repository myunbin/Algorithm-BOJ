#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define ppb(x, y) push_back({x, y})
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 2e5 + 10; // 수정필요
const int INF = 1e9 + 1;
int n, m, p[MAX_N];

int find(int a) {
	if (p[a] < 0) return a;
	return p[a] = find(p[a]);
}

bool merge(int a, int b) {
	a = find(a), b = find(b);
	if (a == b) return false;
	p[a] += p[b];
	p[b] = a;
	return true;
}

int main() {
	fio();
	memset(p, -1, sizeof(p));

	cin >> n >> m;

	vector<int> adj[MAX_N];
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v), adj[v].pb(u);
	}

	vector<int> edge[MAX_N], q(n);
	bool chk[MAX_N] = { false };

	for (int i = 0; i < n; i++) {
		int u; cin >> u;
		chk[u] = true;

		for (int v : adj[u]) {
			if (chk[v]) continue;
			edge[u].pb(v);
		}
		q[i] = u;
	}

	reverse(all(q));

	vector<string> ans;
	for (int i = 0; i < n; i++) {
		int cur = q[i];
		for (int e : edge[cur]) {
			merge(cur, e);
		}
		
		if (-p[find(cur)] == i + 1) ans.pb("YES");
		else ans.pb("NO");
	}

	reverse(all(ans));

	for (auto x : ans) cout << x << '\n';
	
	return 0;
}
