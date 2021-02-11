#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define ends " "
#define pb(x) push_back(x)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define fileio() ifstream file_in("hayfeast.in");ofstream file_out("hayfeast.out")
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
int p[MAX_N], d[MAX_N];
vector<pii> adj[MAX_N];
bool v[MAX_N];

int find(int a) {
	if (a == p[a]) return a;
	return p[a] = find(p[a]);
}

bool merge(int a, int b) {
	a = find(a), b = find(b);
	if (a == b) return false;
	p[b] = a; return true;
}

void dfs(int cur) {
	v[cur] = true;
	for (auto nxt : adj[cur]) {
		if (v[nxt.first]) continue;
		d[nxt.first] = d[cur] + nxt.second;
		dfs(nxt.first);
	}
}

void solve(int n, int m) {
	for (int i = 0; i < MAX_N; i++) 
		p[i] = i, adj[i].clear(), v[i] = false, d[i] = 0;

	vector<tpi> q;

	for (int i = 0; i < m; i++) {
		char c; int a, b;
		cin >> c >> a >> b;
		if (c == '!') {
			int w; cin >> w;
			adj[a].push_back({b, w});
			adj[b].push_back({a, -w});
			merge(a, b);
		}
		else q.push_back({(find(a) != find(b)), a, b}); 
	}
	
	for (int i = 1; i <= n; i++) 
		if (!v[i]) dfs(i);

	for (auto [e, a, b] : q) {
		if (e) cout << "UNKNOWN" << '\n';
		else cout << d[b] - d[a] << '\n';
	}
}
int main() {
	fio();
	
	while (true) {
		int n, m;
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		solve(n, m);
	}
	
	return 0;
}
