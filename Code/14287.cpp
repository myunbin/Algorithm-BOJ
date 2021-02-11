#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define ppb(x, y) push_back({x, y})
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tp;
const int MAX_N = 1e5 + 10;
const int INF = 2e9;
vector<int> adj[MAX_N];
vector<ll> tr;
bool v[MAX_N];
int table[MAX_N], parent[MAX_N], cnt = 1, n, m;

void update(int i, int v) {
	for (; i <= n; i += (i & -i)) tr[i] += v;
}
void update(int l, int r, int v) {
	update(l, v), update(r + 1, -v);
}
ll query(int i, ll s = 0) {
	for (; i > 0; i -= (i & -i)) s += tr[i];
	return s;
}

void dfs(int cur) {
	v[cur] = true;
	table[cur] = cnt++;
	for (int nxt : adj[cur]) {
		if (v[nxt]) continue;
		parent[nxt] = cur;
		dfs(nxt);
	}
}

void track(int cur, int w) {
	int t = table[cur];
	update(t, t, w);
	if (cur == 1) return;
	track(parent[cur], w);
}

int main() {
	fio();

	cin >> n >> m;
	tr.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		if (x == -1) continue;
		adj[x].pb(i);
	}

	dfs(1);

	while (m--) {
		int x, i, w;
		cin >> x >> i;

		if (x == 1) {
			cin >> w;
			track(i, w);
		}
		else cout << query(table[i]) << '\n';
	}
	
	return 0;
}
