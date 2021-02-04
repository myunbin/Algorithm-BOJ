#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define pb(x) push_back(x)
#define ppb(x, y) push_back({x, y})
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int MAX_N = 1e5 + 10;
const int INF = 1e9;
int n;
vector<ll> t(4 * MAX_N), lz(4 * MAX_N);

void propagate(int nd, int le, int ri) {
	if (lz[nd] == 0) return;
	t[nd] += lz[nd] * (ri - le + 1);
	if (le != ri) {
		lz[nd << 1] += lz[nd];
		lz[nd << 1 | 1] += lz[nd];
	}
	lz[nd] = 0;
}

void update(int nd, int le, int ri, int ql, int qr, ll v) {
	propagate(nd, le, ri);
	if (qr < le || ri < ql) return;
	if (ql <= le && ri <= qr) {
		lz[nd] += v;
		propagate(nd, le, ri);
		return;
	}
	int m = le + ri >> 1;
	update(nd << 1, le, m, ql, qr, v);
	update(nd << 1 | 1, m + 1, ri, ql, qr, v);
	t[nd] = t[nd << 1] + t[nd << 1 | 1];
}

ll query(int nd, int le, int ri, int ql, int qr) {
	propagate(nd, le, ri);
	if (qr < le || ri < ql) return 0;
	if (ql <= le && ri <= qr) return t[nd];
	int m = le + ri >> 1;
	return query(nd << 1, le, m, ql, qr) + query(nd << 1 | 1, m + 1, ri, ql, qr);
}

int main() {
	fio();
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;

		ll x = query(1, 1, MAX_N, s, s), y = query(1, 1, MAX_N, e, e);
		cout << x + y << '\n';

		update(1, 1, MAX_N, s, s, -x);
		update(1, 1, MAX_N, e, e, -y);
		update(1, 1, MAX_N, s + 1, e - 1, 1);
	}

	return 0;
}
