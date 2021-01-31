#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define pb(x) push_back(x)
#define ppb(x, y) push_back({x, y})
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 1e5 + 10;

int p[MAX_N], n, m;
vector<int> adj[MAX_N], child[MAX_N];
string s;

int find(int a) {
	if (a == p[a]) return a;
	return p[a] = find(p[a]);
}

void merge(int a, int b) {
	a = find(a), b = find(b);
	if (a == b) return;
	p[b] = a; return;
}

bool chk[MAX_N];
void path(int cur) {
	chk[cur] = true;
	for (int nxt : adj[cur]) {
		if (chk[nxt]) continue;
		if (s[cur] == s[nxt]) merge(cur, nxt);
		path(nxt);
	}
}

int main() {
	fio();
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) p[i] = i;
	cin >> s;

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].pb(v), adj[v].pb(u);
	}

	path(0);
	
	for (int i = 0; i < m; i++) {
		int u, v; char c;
		cin >> u >> v >> c;
		u--, v--;
		if (find(u) == find(v)) cout << (int)(s[u] == c);
		else cout << 1;
	}

	cout << '\n';
	return 0;
}
