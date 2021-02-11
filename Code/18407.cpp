#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define ends " "
#define pb(x) push_back(x)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define fileio() ifstream file_in("input.txt");ofstream file_out("output.txt")
#define double long double
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tpi;
typedef tuple<ll, ll, ll> tpl;
typedef pair<double, ll> pdl;
const int MOD = 1000000007; // PLZ check
const ll LMOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1);
const double eps = 1e-10;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int MAX_N = 2e5 + 10;
int n;
vector<int> tr(4 * MAX_N), lz(4 * MAX_N), v;

void push(int nd, int le, int ri) {
	if (lz[nd] == 0) return;
	tr[nd] = max(tr[nd], lz[nd]);
	if (le != ri) {
		lz[nd << 1] = max(lz[nd << 1], lz[nd]);
		lz[nd << 1 | 1] = max(lz[nd << 1 | 1], lz[nd]);
	}
	lz[nd] = 0;
}

void update(int nd, int le, int ri, int ql, int qr, int v) {
	push(nd, le, ri);
	if (qr < le || ri < ql) return;
	if (ql <= le && ri <= qr) {
		lz[nd] = max(lz[nd], v);
		push(nd, le, ri);
		return;
	}
	int m = le + ri >> 1;
	update(nd << 1, le, m, ql ,qr, v);
	update(nd << 1 | 1, m + 1, ri, ql, qr, v);
	tr[nd] = max(tr[nd << 1], tr[nd << 1 | 1]); 
}

ll query(int nd, int le, int ri, int ql, int qr) {
	push(nd, le, ri);
	if (qr < le || ri < ql) return 0;
	if (ql <= le && ri <= qr) return tr[nd];
	int m = le + ri >> 1;
	return max(query(nd << 1, le, m, ql, qr), query(nd << 1 | 1, m + 1, ri, ql, qr));
}

int idx(int x) {
	return lower_bound(all(v), x) - v.begin();
}
int main() {
	fio();
	
	cin >> n;
	vector<pii> q;
	for (int i = 0; i < n; i++) {
		int w, d, s, e;
		cin >> w >> d;
		s = d, e = d + w;
		v.pb(s), v.pb(e);
		q.push_back({s, e});
	}

	sort(all(v));
	v.erase(unique(all(v)), v.end());
	
	for (auto qu : q) {
		int s = idx(qu.first), e = idx(qu.second);
		int k = query(1, 0, MAX_N, s, e - 1);
		update(1, 0, MAX_N, s, e - 1, k + 1);
	}

	cout << query(1, 0, MAX_N, 0, MAX_N) << endl;
	return 0;
}
