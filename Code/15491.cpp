#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define pb(x) push_back(x)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define fileio() ifstream file_in("boards.txt");ofstream file_out("boards.txt")
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tpi;
typedef tuple<ll, ll, ll> tpl;
typedef pair<double, ll> pdl;
typedef pair<double, int> pdi;
const int MOD = 1000000007;
const ll LMOD = 1e9+7; // PLZ check
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 1e3 + 10;
const int MAXR = 2e5 + 10;
int n;
vector<int> tr, a, b, t, c, adj[MAXN], child[MAXN];
int init(int nd, int le, int ri) {
	if (le == ri) return tr[nd] = b[le];
	int m = le+ri>>1;
	return tr[nd] = max(init(nd<<1, le, m), init(nd<<1|1, m+1, ri));
}

int query(int nd, int le, int ri, int ql, int qr) {
	if (qr < le || ri < ql) return 0;
	if (ql <= le && ri <= qr) return tr[nd];
	int m = le+ri>>1;
	return max(query(nd<<1, le, m, ql, qr), query(nd<<1|1, m+1, ri, ql, qr));
}

bool v[MAXN];
int cnt = 1;
void dfs(int cur) {
	v[cur] = true;
	t[cur] = cnt;
	b[t[cur]] = a[cur];
	int tmp = cnt++;
	for (int nxt : adj[cur]) {
		if (v[nxt]) continue;
		dfs(nxt);
		child[t[cur]].pb(t[nxt]);
	}
	c[tmp] = cnt-tmp;
}

int solve(int cur) {
	int ret = 0;
	for (int nxt : child[cur]) ret += query(1,1,n,nxt,nxt+c[nxt]-1);
	ret += max(query(1,1,n,1,cur-1), query(1,1,n,cur+c[cur],n));
	return ret;
}
int main() {
	fio();
	cin >> n;
	tr.resize(4*n), a.resize(n+1), b.resize(n+1), t.resize(n+1), c.resize(n+1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 0, u, v; i < n-1; i++) {
		cin >> u >> v;
		adj[u].pb(v), adj[v].pb(u);
	}

	dfs(1);
	init(1,1,n);

	int ans = 0;
	for (int i = 1; i <= n; i++) ans = max(ans, solve(i));
	cout << ans << endl;
	return 0;
}

