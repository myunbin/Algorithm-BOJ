#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define ppb(x, y) push_back({x, y})
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tp;
const int MAX_N = 1e5 + 10;
const int INF = 2e9;

int pos[MAX_N], p[MAX_N], n, m;
vector<tp> a;
vector<int> b;

int find(int a) {
	if (a == p[a]) return a;
	return p[a] = find(p[a]);
}

bool merge(int a, int b) {
	a = find(a), b = find(b);
	if (a == b) return false;
	p[b] = a; return true;
}

bool ok(int x) {
	for (int i = 0; i < MAX_N; i++) p[i] = i;
	
	int idx = lower_bound(all(b), x) - b.begin();
	for (int i = idx; i < m; i++) {
		auto [w, u, v] = a[i];
		merge(u, v);
	}

	for (int i = 1; i <= n; i++) {
		if (find(i) != find(pos[i])) 
			return false;
	}
	return true;
}

int main() {
	fio();
//	freopen("wormsort.in","r",stdin);
//	freopen("wormsort.out","w",stdout);

	cin >> n >> m;
	bool f = true;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		pos[x] = i;
		if (x != i) f = false;
	}
	
	if (f) {
		cout << -1 << '\n';
		return 0;
	}

	int mw = 0;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		a.push_back({w, u, v});
		b.pb(w);
		mw = max(mw, w);
	}
	sort(all(a));
	sort(all(b));

	int le = 0, ri = INF, ans = 0;
	while (le <= ri) {
		int mid = le + ri >> 1;
		if (ok(mid)) {
			ans = mid;
			le = mid + 1;
		}
		else ri = mid - 1;
	}

	cout << ans << '\n';
	return 0;
}
