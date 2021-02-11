#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define ppb(x, y) push_back({x, y})
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tp;
const int MAX_N = 1e5;
const int INF = 2e9;
int n;
vector<int> tr, a, q;

int init(int nd, int le, int ri) {
	if (le == ri) return tr[nd] = 1;
	int m = le + ri >> 1;
	return tr[nd] = init(nd << 1, le, m) + init(nd << 1 | 1, m + 1, ri);
}

void update(int nd, int le, int ri, int i, int v) {
	if (i < le || ri < i) return;
	if (le == ri) {
		tr[nd] += v;
		return;
	}
	int m = le + ri >> 1;
	update(nd << 1, le, m, i, v);
	update(nd << 1 | 1, m + 1, ri, i, v);
	tr[nd] = tr[nd << 1] + tr[nd << 1 | 1];
}

int query(int nd, int le, int ri, int k) {
	if (le == ri) return le;
	int m = le + ri >> 1;
	if (tr[nd << 1] < k) return query(nd << 1 | 1, m + 1, ri, k - tr[nd << 1]);
	return query(nd << 1, le, m, k);
}

int main() {
	fio();

	cin >> n;
	a.resize(n), tr.resize(4 * n), q.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> q[i];
	sort(all(a));
	init(1, 0, n - 1);

	vector<int> ans(n);
	for (int i = n - 1; i >= 0; i--) {
		int idx = query(1, 0, n - 1, q[i] + 1);
		update(1, 0, n - 1, idx, -1);
		ans[i] = a[idx];
	}

	for (int a : ans) cout << a << '\n';
	return 0;
}
