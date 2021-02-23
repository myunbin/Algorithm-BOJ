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
const int MAXN = 1e4 + 10;
const int MAXR = 2e5 + 10;
int p[MAXN];
int find(int a) {
	if (a == p[a]) return a;
	return p[a] = find(p[a]);
}

bool merge(int a, int b) {
	a = find(a), b = find(b);
	if (a == b) return false;
	p[b] = a; return true;
} 

int main() {
	fio();
	for (int i = 0; i < MAXN; i++) p[i] = i;
	
	int n, p, a[MAXN], r = INF;
	vector<tpi> e;
	cin >> n >> p;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		r = min(r, a[i]);
	}

	for (int i = 0; i < p; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e.push_back({a[u]+a[v]+2*w, u, v});
	}
	sort(all(e));

	ll ans = r;
	for (auto [w, u, v] : e) {
		if (merge(u, v)) ans += w; 
	}

	cout << ans << endl;
	return 0;
}

