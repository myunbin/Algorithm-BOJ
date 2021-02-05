#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define ppb(x, y) push_back({x, y})
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 4001;
const int INF = 1e9 + 1;

int same(int x, vector<ll> &a) { return upper_bound(all(a), x) - lower_bound(all(a), x);}

int main() {
	fio();

	int n;
	cin >> n;

	vector<ll> a(n), b(n), c(n), d(n), ab, cd;
	for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ab.pb(a[i] + b[j]);
			cd.pb(c[i] + d[j]);
		}
	}

	sort(all(ab)), sort(all(cd));
	
	int sq = n * n;
	int le = 0, ri = sq - 1;
	
	ll ans = 0;
	
	while (le < sq && ri >= 0) {
		if (ab[le] + cd[ri] == 0) {
			int dl = same(ab[le], ab), dr = same(cd[ri], cd); 
			ans += 1LL * dl * dr;
			le += dl, ri -= dr;
		}
		else if (ab[le] + cd[ri] > 0) ri--;
		else le++;
	}

	cout << ans << '\n';
	return 0;
}
