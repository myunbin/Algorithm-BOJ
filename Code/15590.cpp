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

int main() {
	fio();

	int n, m, r;
	cin >> n >> m >> r;
	vector<ll> a(n), c(max(n, r), 0);
	vector<pll> b(m);

	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i].second >> b[i].first;
	for (int i = 0; i < r; i++) cin >> c[i];

	sort(all(a), greater<int>());
	sort(all(b), greater<pii>());
	sort(all(c));

	int mpos = 0, rpos = 0;
	if (r > n) rpos = r - n;

	ll ans = 0;

	for (ll cur : a) {
		ll milk = 0, rent = 0;
		ll t = cur;

		while (mpos < m && t > 0) {
			ll x = min(b[mpos].second, t);
			milk += x * b[mpos].first;
			t -= x;
			b[mpos].second -= x;
			if (t > 0) mpos++;
		}

		rent = c[rpos++];
		ans += max(rent, milk);
	}

	cout << ans << '\n';
	return 0;
}
