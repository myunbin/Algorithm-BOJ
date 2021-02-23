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
const int MOD = 987654321;
const ll LMOD = 1e9+7; // PLZ check
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 110;
const int MAXR = 2e5 + 10;
int n, m, r, t[MAXN];
vector<pii> adj[MAXN];
int f(int s) {
	int d[MAXN];
	bool v[MAXN] = {false};
	fill(d, d+MAXN, INF);
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	d[s] = 0;
	pq.push({d[s], s});

	while (!pq.empty()) {
		int cur = pq.top().second;
		pq.pop();
		if (v[cur]) continue;
		v[cur] = true;

		for (auto [nxt, len] : adj[cur]) {
			if (v[nxt]) continue;
			if (d[nxt] > d[cur]+len) {
				d[nxt] = d[cur]+len;
				pq.push({d[nxt], nxt});
			}
		}
	}

	int ret = 0;
	for (int i = 1; i <= n; i++) {
		if (d[i] <= m) ret += t[i];
	}

	return ret;
}

int main() {
	fio();
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) cin >> t[i];
	for (int i = 0; i < r; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		adj[a].push_back({b, l});
		adj[b].push_back({a, l});
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) ans = max(ans, f(i));
	cout << ans << endl;
	return 0;
}

