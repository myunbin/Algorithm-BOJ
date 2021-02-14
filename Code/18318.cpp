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
vector<ll> b, d, tr(4*MAXR);
ll n, p, dp[MAXR];
struct tup{ll x, y;int i, s;};
int idx(int x) {
	return lower_bound(all(b), x) - b.begin();
}

void update(int nd, int le, int ri, int i, ll v) {
	if (i<le || ri<i) return;
	if (le == ri) {
		tr[nd] = max(tr[nd],v);
		return;
	}
	int m = le + ri >> 1;
	update(nd<<1, le, m, i, v);
	update(nd<<1|1, m+1, ri, i, v);
	tr[nd] = max(tr[nd<<1], tr[nd<<1|1]);
}

ll query(int nd, int le, int ri, int ql, int qr) {
	if (qr<le || ri<ql) return 0;
	if (ql<=le && ri<=qr) return tr[nd];
	int m = le + ri >> 1;
	return max(query(nd<<1, le, m, ql, qr), query(nd<<1|1, m+1, ri, ql, qr));
}

int main() {
	fio();
	
	cin >> n >> p;
	vector<tup> a;
	for (int i = 0; i < p; i++) {
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		a.push_back({x1, y1, i, 1});
		a.push_back({x2, y2, i, -1});
		d.pb(x2 - x1 + y2 - y1);
		b.pb(y1), b.pb(y2);
	}
	sort(all(b)), b.erase(unique(all(b)), b.end());
	sort(all(a), [&](auto p, auto q) {
		if (p.x == q.x) return p.y > q.y;
		return p.x > q.x; 
	});

	for (auto [x, y, i, s] : a) {
		if (s == 1) update(1, 0, MAXR, idx(y), dp[i]);
		else dp[i] = query(1, 0, MAXR, idx(y), MAXR) + d[i];
	}	
	
	cout << 2*n - tr[1] << '\n';
	return 0;
}
