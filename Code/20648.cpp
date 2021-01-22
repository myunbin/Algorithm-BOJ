#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define ppb(x, y) push_back({x, y})
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
vector<int> a, t;
vector<pii> p;
int n;

void update(int i, int v) {
	for (; i <= n; i += (i & -i)) t[i] += v;
}
int query(int i, int s = 0) {
	for (; i >= 1; i -= (i & -i)) s += t[i];
	return s;
}

int main() {
	fio();

	cin >> n;
	t.resize(n + 1);

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		p.ppb(x, y);
		a.pb(y);
	}

	sort(all(a)), sort(all(p)); 
	a.erase(unique(all(a)), a.end());
	
	vector<int> y(n);
	for (int i = 0; i < n; i++) 
		y[i] = lower_bound(all(a), p[i].second) - a.begin() + 1;

	
	ll ans = 1 + n;
	for (int i = 0; i < n; i++) {
		int py = y[i];
		for (int j = i + 1; j < n; j++) {
			int cury = y[j];

			int big = query(n) - query(max(cury, py));
			int small = query(min(cury, py));
			
			update(cury, 1);

			ans += 1LL * (big + 1) * (small + 1);
		}

		fill(all(t), 0);
	}
	
	cout << ans << '\n';

	return 0;
}
