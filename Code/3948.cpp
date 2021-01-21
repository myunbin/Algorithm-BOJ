#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define ppb(x, y) push_back({x, y})
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 21;
const int MOD = 1e6;
ll dp[MAX_N][MAX_N][2];
int n;

ll go(int l, int r, bool u) {
	if (l == 0 && r == 0) return 1;
	
	ll &ret = dp[l][r][u];
	if (ret != -1) return ret;

	ret = 0; 
	int s = l + r;
	if (u) {
		for (int k = 0; k < l; k++) {
			ret += go(k, s - k - 1, !u);
		}
	}
	else {
		for (int k = 0; k < r; k++) {
			ret += go(s - k - 1, k, !u);
		}
	}
	return ret;
}

int main() {
	fio();
	memset(dp, -1, sizeof(dp));

	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		if (n == 1) {
			cout << 1 << '\n';
			continue;
		}
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			ans += go(i, n - i - 1, 0);
			ans += go(i, n - i - 1, 1);
		}

		cout << ans << '\n';
	}
	return 0;
}
