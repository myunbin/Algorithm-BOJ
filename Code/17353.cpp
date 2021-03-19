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
const int MAXN = 1e6+10;
const int MAXR = 2e5 + 10;

struct segtree {
	vector<ll> tr, lz, d;
	segtree(int sz) : tr(4*sz), lz(4*sz), d(sz+1) {}

	void init(int nd, int l, int r) {
		if (l == r) {
			tr[nd] = d[l];
			return;
		}
		int m = l+r>>1;
		init(nd<<1, l, m);
		init(nd<<1|1, m+1, r);
		tr[nd] = tr[nd<<1]+tr[nd<<1|1];
	}

	void push(int nd, int l, int r) {
		tr[nd] += (r-l+1)*lz[nd];
		if (l != r) {
			lz[nd<<1] += lz[nd];
			lz[nd<<1|1] += lz[nd];
		}
		lz[nd] = 0;
	}

	void update(int nd, int l, int r, int ql, int qr, ll v) {
		push(nd, l, r);
		if (qr < l || r < ql) return;
		if (ql <= l && r <= qr) {
			lz[nd] += v;
			push(nd, l, r);
			return;
		}
		int m = l+r>>1;
		update(nd<<1, l, m, ql, qr, v);
		update(nd<<1|1, m+1, r, ql, qr, v);
		tr[nd] = tr[nd<<1]+tr[nd<<1|1];
	}

	ll qry(int nd, int l, int r, int ql, int qr) {
		push(nd, l, r);
		if (qr < l || r < ql) return 0;
		if (ql <= l && r <= qr) return tr[nd];
			int m = l+r>>1;
			return qry(nd<<1, l, m, ql, qr)+qry(nd<<1|1, m+1, r, ql, qr);
		}
};

int main() {
	fio();
	
	int n;
	cin >> n;
	segtree st(n);

	int la = 0;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		st.d[i] = x-la;
		la = x;
	}
	st.init(1,1,n);

	int m; cin >> m;
	while (m--) {
		int q; cin >> q;
		if (q == 1) {
			int x, y;
			cin >> x >> y;
			st.update(1,1,n,x,y,1);
			if (y != n) st.update(1,1,n,y+1,y+1,-(y-x+1));
		}
		else {
			int x; cin >> x;
			cout << st.qry(1,1,n,1,x) << endl;
		}
	}
	return 0;
}
