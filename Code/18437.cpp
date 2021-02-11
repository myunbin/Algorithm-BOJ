#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define ends " "
#define pb(x) push_back(x)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define fileio() ifstream file_in("input.txt");ofstream file_out("output.txt")
#define double long double
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tpi;
typedef tuple<ll, ll, ll> tpl;
typedef pair<double, ll> pdl;
const int MOD = 1000000007; // PLZ check
const ll LMOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1);
const double eps = 1e-10;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int MAX_N = 1e5 + 10;
int n, m, cnt = 1, t[MAX_N], cn[MAX_N];
bool v[MAX_N];
vector<int> tr, lz, adj[MAX_N];

void push(int nd, int le, int ri) {
	if (lz[nd] == -1) return;
	tr[nd] = (ri - le + 1) * lz[nd];
	if (le != ri) {
		lz[nd << 1] = lz[nd];
		lz[nd << 1 | 1] = lz[nd];
	}
	lz[nd] = -1;
}

void update(int nd, int le, int ri, int ql, int qr, int v) {
	push(nd, le, ri);
	if (qr < le || ri < ql) return;
	if (ql <= le && ri <= qr) {
		lz[nd] = v;
		push(nd, le, ri);
		return;
	}
	int m = le + ri >> 1;
	update(nd << 1, le, m, ql ,qr, v);
	update(nd << 1 | 1, m + 1, ri, ql, qr, v);
	tr[nd] = tr[nd << 1] + tr[nd << 1 | 1]; 
}

ll query(int nd, int le, int ri, int ql, int qr) {
	push(nd, le, ri);
	if (qr < le || ri < ql) return 0;
	if (ql <= le && ri <= qr) return tr[nd];
	int m = le + ri >> 1;
	return query(nd << 1, le, m, ql, qr) + query(nd << 1 | 1, m + 1, ri, ql, qr);
}

void dfs(int cur) {
	v[cur] = true;
	t[cur] = cnt;
	int tmp = cnt++;
	for (int nxt : adj[cur]) {
		if (v[nxt]) continue;
		dfs(nxt);
	}
	cn[tmp] = cnt - tmp;
}

int main() {
	fio();
	
	cin >> n;
	tr.resize(4 * n), lz.resize(4 * n, -1);
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		if (i != 1) adj[x].pb(i);
	}	

	dfs(1);
	update(1, 1, n, 1, cn[1], 1);

	cin >> m;
	while (m--) {
		int x, i;
		cin >> x >> i;
		int c = t[i];
		if (x == 1) update(1, 1, n, c + 1, c + cn[c] - 1, 1);
		else if (x == 2) update(1, 1, n, c + 1, c + cn[c] - 1, 0);
		else cout << query(1, 1, n, c + 1, c + cn[c] - 1) << '\n';
	}
	return 0;

}
