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
const ll LMOD = 1e9; // PLZ check
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 1e5 + 10;
const int MAXR = 2e5 + 10;

int n, m, p[MAXN];
ll sum = 0;
int find(int a) {
	if (p[a] < 0) return a;
	return p[a] = find(p[a]);
}

bool merge(int a, int b) {
	a = find(a), b = find(b);
	if (a == b) return false;
	sum += 1LL * p[a] * p[b];
	p[a] += p[b];
	p[b] = a;
	return true;
}

int main() {
	fio();
	memset(p, -1, sizeof(p));

	vector<tpi> e;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e.push_back({w, u, v});
	}
	sort(all(e), greater<tpi>());

	ll ans = 0;
	for (auto [w, u, v] : e) {
		merge(u, v);
		ans += sum * w;
		if (ans >= 1e9) ans %= LMOD;
	}
	cout << ans << '\n';
	return 0;
}

