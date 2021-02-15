#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
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
const int MOD = 1000000007; // PLZ check
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 1e5 + 10;
const int MAXR = 2e5 + 10;
vector<int> adj[MAXN];
int n, r, q, dp[MAXN], cnt;
bool v[MAXN];
void dfs(int cur) {
	v[cur] = true;
	int tmp = cnt++;
	for (int nxt : adj[cur]) {
		if (v[nxt]) continue;
		dfs(nxt);
	
	}
	dp[cur] = cnt-tmp;
}

int main() {
	fio();
	
	cin >> n >> r >> q;
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v), adj[v].pb(u);
	}

	dfs(r);
	
	while (q--) {
		int u; cin >> u;
		cout << dp[u] << '\n';
	}

	return 0;
}
