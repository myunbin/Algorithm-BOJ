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
const int MAXN = 1e4 + 10;
const int MAXR = 2e5 + 10;

int n, c[MAXN];
vector<pii> adj[MAXN];
bool v[MAXN];
ll d[MAXN], dp[MAXN], ans;
void init() {
	ans = LINF;
	for (int i = 0; i < MAXN; i++) {
		adj[i].clear();
		v[i] = false, d[i] = 0, dp[i] = 0, c[i] = 0;
	}
}

int cnt = 0;
void dfs1(int cur) {
	v[cur] = true;
	int tmp = cnt++;
	for (auto [nxt, cost] : adj[cur]) {
		if (v[nxt]) continue;
		dfs1(nxt);
		d[cur] += d[nxt] + cost * c[nxt];
	}
	c[cur] = cnt - tmp;
}

void dfs2(int cur, ll cand) {
	ans = min(ans, cand);
	v[cur] = true;
	for (auto [nxt, cost] : adj[cur]) {
		if (v[nxt]) continue;
		dfs2(nxt, cand + cost*(n - 2*c[nxt]));
	}
}

void solve() {
	for (int i = 0; i < n - 1; i++) {
			int x, y, w;
			cin >> x >> y >> w;
			adj[x].push_back({y, w});
			adj[y].push_back({x, w});
	}

	dfs1(0);
	memset(v, false, sizeof(v));
	dfs2(0, d[0]);
	
	cout << ans << endl;
}

int main() {
	fio();

	while (true) {
		cin >> n;
		if (n == 0) return 0;
		init();
		solve();
	}

	return 0;
}

