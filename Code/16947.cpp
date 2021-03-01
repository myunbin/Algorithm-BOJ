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
const int MOD = 1e6;
const ll LMOD = 1e9+7; // PLZ check
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 3e3 + 10;
const int MAXR = 2e5 + 10;
int n;
bool v[MAXN], inc[MAXN];
vector<int> adj[MAXN];
int p[MAXN], anc[MAXN];

int find(int a) {
	if (a == p[a]) return a;
	return p[a] = find(p[a]);
}

bool merge(int a, int b) {
	a = find(a), b = find(b);
	if (a == b) return false;
	p[b] = a; return true;
}

void fcy(int cur, int e) {
	inc[cur] = true;
	if (cur == e) return;
	fcy(anc[cur], e);
}

void dfs(int cur, int s, int e) {
	if (cur == e) fcy(e, s);
	v[cur] = true;
	for (int nxt : adj[cur]) {
		if (v[nxt]) continue;
		anc[nxt] = cur;
		dfs(nxt, s, e);
	}
}

int bfs(int s) {
	queue<pii> q;
	q.push({s, 0});
	v[s] = true;
	
	while (!q.empty()) {
		auto [cur, d] = q.front();
		if (inc[cur]) return d;
		q.pop();

		for (int nxt : adj[cur]) {
			if (v[nxt]) continue;
			v[nxt] = true;
			q.push({nxt, d+1});
		}
	}
}

int main() {
	fio();
	for (int i = 0; i < MAXN; i++) p[i] = i;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v), adj[v].pb(u);
		if (!merge(u, v)) dfs(u, u, v);
	}

	for (int i = 1; i <= n; i++) {
		memset(v, false, sizeof(v));
		cout << bfs(i) << ' ';
	}
	
	return 0;
}
