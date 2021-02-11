#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define ppb(x, y) push_back({x, y})
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tp;
const int MAX_N = 1010;
const int INF = 2e9;
int n, m, k, s, t;
vector<tp> adj[MAX_N];
vector<int> v;
bool chk[MAX_N];

void dfs(int c, int x) {
	chk[c] = true;
	for (auto [nxt, c, d] : adj[c]) {
		if (chk[nxt] || x < c || d < x) continue;
		dfs(nxt, x);
	}
}

bool f(int x) {
	memset(chk, false, sizeof(chk));
	dfs(s, x);
	return chk[t];
}

int main() {
	fio();

	cin >> n >> m >> k >> s >> t;
	for (int i = 0; i < m; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		adj[a].emplace_back(b, c, d);
		v.pb(c); v.pb(d + 1);
	}

	sort(all(v));
	v.erase(unique(all(v)), v.end());

	int bf = 0;
	ll ans = 0;
	for (int c : v) {
		ans += (c - bf) * f(bf);
		bf = c;
	}

	cout << ans << '\n';

	return 0;
}
