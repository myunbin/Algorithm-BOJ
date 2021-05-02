#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define pb(x) push_back(x)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define fileio() ifstream file_in("cowjump.in");ofstream file_out("cowjump.out")
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
const int MAXN = 555;
const int MAXR = 2e5 + 10;

void solve() {
	int n, m, w;
	cin >> n >> m >> w;
	vector<tpi> e;
	for (int i = 0; i < m; i++) {
		int u, v, t; cin >> u >> v >> t;
		e.push_back({u, v, t});
		e.push_back({v, u, t});
	}
	for (int i = 0; i < w; i++) {
		int u, v, t; cin >> u >> v >> t;
		e.push_back({u, v, -t});
	}

	int d[MAXN];
	fill(d, d+MAXN, INF);
	d[1] = 0; bool cy = false;
	
	for (int i = 0; i < n; i++) {
		for (auto [u, v, t] : e) {
			if (d[v] > d[u]+t) {
				d[v] = d[u]+t;
				if (i == n-1) {
					cy = true;
					break;
				}
			}
		}
	}

	cout << (cy ? "YES" : "NO") << endl;
}
int main() {
	fio();
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}
