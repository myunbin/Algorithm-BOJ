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
const int MAX_N = 1e6 + 1;
const int MOD = 1e9;
int n;
ll dp[MAX_N];

ll go(int i) {
	if (i <= 1) return 0;
	if (i == 2) return 1;

	ll &ret = dp[i];
	if (ret != -1) return ret;

	ret = (i - 1) * (go(i - 1) % MOD + go(i - 2) % MOD) % MOD;
	ret %= MOD;

	return ret;
}

int main() {
	fio();
	memset(dp, -1, sizeof(dp));
	
	cin >> n;
	cout << go(n) << '\n';
	return 0;
}
