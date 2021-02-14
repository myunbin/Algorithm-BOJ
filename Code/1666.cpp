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
const int MAXR = 1e5 + 10;
struct tp {pii c; int i, s;};
vector<int> tr(4*MAXR);
int dp[MAXR];

void update(int nd, int le, int ri, int i, int v) {
	if (i < le || ri < i) return;
	if (le == ri) {
		tr[nd] = max(tr[nd], v);
		return;
	}
	int m = le + ri >> 1;
	update(nd<<1, le, m, i, v);
	update(nd<<1|1, m+1, ri, i, v);
	tr[nd] = max(tr[nd<<1], tr[nd<<1|1]);
}

int query(int nd, int le, int ri, int ql, int qr) {
	if (qr < le || ri < ql) return 0;
	if (ql <= le && ri <= qr) return tr[nd];
	int m = le + ri >> 1;
	return max(query(nd<<1, le, m, ql, qr), query(nd<<1|1, m+1, ri, ql, qr));
}

int main() {
	fio();

	int n;
	cin >> n;

	vector<tp> sq;
	for (int i = 0; i < n; i++) {
		pii a, b;
		cin >> a.f >> a.s >> b.f >> b.s;
		sq.push_back({a, i, 1});
		sq.push_back({b, i, -1});
	}

	sort(all(sq), [&](tp a, tp b){
		if (a.c.f == b.c.f) return a.c.s < b.c.s;
		return a.c.f > b.c.f;
	});		

	for (auto [c, i, s] : sq) {
		int x = c.f, y = c.s;
		if (s == 1) update(1, 0, MAXR, y, dp[i]);
		else dp[i] = query(1, 0, MAXR, y+1, MAXR)+1;
	}

	cout << tr[1] << '\n';
	return 0;
}
