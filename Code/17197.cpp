#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define pb(x) push_back(x)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define fileio() ifstream file_in("boards.txt");ofstream file_out("boards.txt")
#define f first
#define s second
#define double long double
#define db double
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tpi;
typedef tuple<ll, ll, ll> tpl;
typedef pair<double, ll> pdl;
typedef pair<double, int> pdi;
typedef pair<double, double> pdd;
const int MOD = 987654321;
const ll LMOD = 1e9+7; // PLZ check
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 1e5+10;
const int MAXR = 2e5 + 10;

pii c[MAXN];
vector<int> adj[MAXN];
bool v[MAXN];
ll bfs(int s) {
	queue<int> q;
	q.push(s);
	int minx, miny, maxx, maxy;
	minx = maxx = c[s].f;
	miny = maxy = c[s].s;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int nxt : adj[cur]) {
			if (v[nxt]) continue;
			v[nxt] = true;
			q.push(nxt);
			minx = min(minx, c[nxt].f);
			miny = min(miny, c[nxt].s);
			maxx = max(maxx, c[nxt].f);
			maxy = max(maxy, c[nxt].s);
		}
	}

	return 1LL*2*(maxx-minx + maxy-miny);
}

int main() {
	fio();

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		cin >> c[i].f >> c[i].s;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v), adj[v].pb(u);
	}
	
	ll ans = LINF;
	for (int i = 1; i <= n; i++) {
		if (!v[i]) ans = min(ans, bfs(i));
	}
	cout << ans << endl;

	return 0;
}

