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
const int MAXN = 1e5 + 10;
vector<pii> tr; vector<int> s;

void init(int nd, int le, int ri) {
	if (le == ri) {
		tr[nd] = {s[le], s[le]};
		return;
	}
	int m = le + ri >> 1;
	init(nd<<1, le, m), init(nd<<1|1, m+1, ri);
	auto a = tr[nd<<1], b = tr[nd<<1|1];
	tr[nd] = {min(a.f, b.f), max(a.s, b.s)};
}

void update(int nd, int le, int ri, int i, int v) {
	if (i < le || ri < i) return;
	if (le == ri) {
		tr[nd] = {v, v};
		return;
	}
	int m = le + ri >> 1;
	update(nd<<1, le, m, i, v), update(nd<<1|1, m+1, ri, i, v);
	auto a = tr[nd<<1], b = tr[nd<<1|1];
	tr[nd] = {min(a.f, b.f), max(a.s, b.s)};
}

pii query(int nd, int le, int ri, int ql, int qr) {
	if (qr < le || ri < ql) return {INF, -INF};
	if (ql <= le && ri <= qr) return tr[nd];
	int m = le + ri >> 1;
	auto a = query(nd<<1, le, m, ql, qr), b = query(nd<<1|1, m+1, ri, ql, qr);
	return {min(a.f, b.f), max(a.s, b.s)};
}

void solve() {
	int n, k; cin >> n >> k;
	tr.clear(), s.resize(n), tr.resize(4 * n);
	for (int i = 0; i < n; i++) s[i] = i;
	init(1, 0, n - 1);
	while (k--) {
		int q, a, b;
		cin >> q >> a >> b;
		if (q) {
			auto p = query(1, 0, n - 1, a, b);
			cout << (p == make_pair(a, b) ? "YES" : "NO") << '\n';
		}
		else {
			update(1, 0, n - 1, a, s[b]);
			update(1, 0, n - 1, b, s[a]);
			swap(s[a], s[b]);
		}
	}
}
int main() {
	fio();
	int t; cin >> t;
	while (t--) solve();
	return 0;
}
