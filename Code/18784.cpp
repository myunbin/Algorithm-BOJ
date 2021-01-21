#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define ppb(x, y) push_back({x, y})
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 2e5 + 5;
const int MOD = 1e9 + 7;
const int OFF = 1e4;
vector<pii> a, cord[MAX_N];
ll sum[MAX_N][2];
int n;

void calc(int k) {
	for (int i = 0; i < MAX_N; i++) {
		if (cord[i].empty()) continue;
		sort(all(cord[i]));

		ll s = 0;
		for (auto p : cord[i]) {
			int c = p.first;
			s += (c - cord[i][0].first);
			s %= MOD;
		}

		int sz = cord[i].size();
		for (int j = 0; j < sz; j++) {
			int idx = cord[i][j].second;
			if (j != 0) {
				s += (2 * j - sz) * (cord[i][j].first - cord[i][j - 1].first);
				s %= MOD;
			}
			sum[idx][k] = s;
		}
	}
}
int main() {
	fio();

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		a.ppb(x, y);
	}
	
	for (int i = 0; i < n; i++) {
		int x = a[i].first, y = a[i].second + OFF;
		cord[y].ppb(x, i);
	}
	calc(0);

	for (int i = 0; i < MAX_N; i++) cord[i].clear();

	for (int i = 0; i < n; i++) {
		int x = a[i].first + OFF, y = a[i].second;
		cord[x].ppb(y, i);
	}
	calc(1);

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ans += sum[i][0] * sum[i][1];
		ans %= MOD;
	}
	
	cout << ans << '\n';
	
	return 0;
}
