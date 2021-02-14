#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define fileio() ifstream file_in("input.txt");ofstream file_out("output.txt")
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
const int MAXN = 2020;
const int MAXR = 4e5 + 10;
vector<pll> tr(4*MAXR);
vector<tuple<ll,ll,ll,ll>> a;
vector<ll> b;
void update(int nd, int le, int ri, int ql, int qr, int v) {
	if (qr<le || ri<ql) return;
	if (ql<=le && ri<=qr) tr[nd].f += v;
	else {
		int m = le + ri >> 1;
		update(nd<<1, le, m, ql, qr, v);
		update(nd<<1|1, m + 1, ri, ql, qr, v);
	}

	if (tr[nd].f == 0) {
		if (le == ri) tr[nd].s = 0;
		else tr[nd].s = tr[nd<<1].s + tr[nd<<1|1].s;
	}
	else tr[nd].s = b[ri+1] - b[le];
} 

int idx(int x) {
	return lower_bound(all(b), x) - b.begin();
}

int main() {
	fio();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll x1, x2, y1, y2;
		cin >> x1 >> x2 >> y1 >> y2;
		a.push_back({x1, y1, y2, 1});
		a.push_back({x2, y1, y2, -1});
		b.pb(y1), b.pb(y2);
	}
	sort(all(a)), sort(all(b));
	b.erase(unique(all(b)), b.end());

	ll l = get<0>(a[0]);
	ll ans = 0;
	for (auto [x, y1, y2, s] : a) {
		ans += (x - l) * tr[1].s;
		y1 = idx(y1), y2 = idx(y2);
		update(1, 0, MAXR, y1, y2-1, s);
		l = x;
	}
	cout << ans << '\n';
	return 0;
}
