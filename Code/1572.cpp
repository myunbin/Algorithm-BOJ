#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define ppb(x, y) push_back({x, y})
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX = 65536;
vector<int> t(4 * MAX + 1, 0), a;
int n, k;

int update(int node, int le, int ri, int idx, int v) {
	if (idx < le || ri < idx) return t[node];
	if (le == ri) return t[node] += v;
	int mid = le + ri >> 1;
	return t[node] = update(node * 2, le, mid, idx, v) + update(node * 2 + 1, mid + 1, ri, idx, v);
}

int query(int node, int le, int ri, int k) {
	if (le == ri) return le;
	int mid = le + ri >> 1;
	if (k <= t[node * 2]) return query(node * 2, le, mid, k);
	else return query(node * 2 + 1, mid + 1, ri, k - t[node * 2]);	
}

int main() {
	fio();

	cin >> n >> k;
	int f = (k + 1) >> 1;
	a.resize(n);
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		update(1, 0, MAX, a[i], 1);
		if (i < k - 1) continue;
		ans += 1LL * query(1, 0, MAX, f);
		update(1, 0, MAX, a[i - k + 1], -1);
	}

	cout << ans << '\n';
	return 0;
}
