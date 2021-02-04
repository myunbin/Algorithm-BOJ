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
typedef pair<ll, ll> pll;
const int MAX_N = 1e5 + 10;
const int INF = 1e9;

vector<int> adj[MAX_N];
vector<ll> tr, lz;
bool v[MAX_N];
int table[MAX_N], child[MAX_N], cnt = 1, n, m;

void propagate(int nd, int le, int ri) {
	if (lz[nd] == 0) return;
	tr[nd] += (ri - le + 1)  * lz[nd];
	if (le != ri) {
		lz[nd << 1] += lz[nd];
		lz[nd << 1 | 1] += lz[nd];
	}
	lz[nd] = 0;
}

void update(int nd, int le, int ri, int ql, int qr, ll v) {
	propagate(nd, le, ri);
	if (qr < le || ri < ql) return;
	if (ql <= le && ri <= qr) {
		lz[nd] += v;
		propagate(nd, le, ri);
		return;
	}
	int m = le + ri >> 1;
	update(nd << 1, le, m, ql, qr, v);
	update(nd << 1 | 1, m + 1, ri, ql, qr, v);
	tr[nd] = tr[nd << 1] + tr[nd << 1 | 1];
}

ll query(int nd, int le, int ri, int ql, int qr) {
	propagate(nd, le, ri);
	if (qr < le || ri < ql) return 0;
	if (ql <= le && ri <= qr) return tr[nd];
	int m = le + ri >> 1;
	return query(nd << 1, le, m, ql, qr) + query(nd << 1 | 1, m + 1, ri, ql, qr);
}

void dfs(int cur) {
	v[cur] = true;
	table[cur] = cnt;
	int tmp = cnt++;
	for (int nxt : adj[cur]) {
		if (v[nxt]) continue;
		dfs(nxt);
	}
	child[tmp] = cnt - tmp;
}

int main() {
	fio();

	cin >> n >> m;

	tr.resize(4 * n), lz.resize(4 * n);

	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		if (x == -1) continue;
		adj[x].pb(i);
	}

	dfs(1);

	while (m--) {
		int x, i, w;
		cin >> x >> i;
		int c = table[i];

		if (x == 1) {
			cin >> w;
			update(1, 1, n, c, c + child[c] - 1, 1LL * w);
		}
		else {
			cout << query(1, 1, n, c, c) << '\n';
		}
	}

	return 0;
}
