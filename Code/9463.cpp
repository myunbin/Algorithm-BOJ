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
int n;
vector<int> t;
void update(int i) {
	for (; i <= n; i += (i & -i)) t[i]++;
}

int query(int i, int s = 0) {
	for (; i >= 1; i -= (i & -i)) s += t[i];
	return s; 
}

void solve() {
	t.clear();
	t.resize(n + 1);

	vector<int> a(n + 1);
	vector<pii> e(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		e[a[i]].first = i;
	}
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		e[x].second = i; 
	} 
	
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		int ed = e[a[i]].second;
		ans += query(n) - query(ed);
		update(ed);
	}

	cout << ans << '\n';
}
int main() {
	fio();

	int tr;
	cin >> tr;
	
	while (tr--) {
		cin >> n;

		solve();
	}
	return 0;
}
