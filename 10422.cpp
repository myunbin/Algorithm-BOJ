#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 5050;
const ll MOD = 1000000007LL;
ll dp[MAX];

ll go(int n) {
	ll &ret = dp[n];
	if (ret != -1) return ret;
	
	if (n == 0) return ret = 1;
	
	ret = 0;
	for (int i = 2; i <= n; i += 2) {
		ret += go(n - i) * go(i - 2);
		ret %= MOD;
	}
	
	return ret;
}


int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);
	
	memset(dp, -1, sizeof(dp));
	
	int t;
	cin >> t;
	
	for (int i = 1; i <= MAX; i += 2) dp[i] = 0;
	
	while (t--) {
		int l;
		cin >> l;
		
		cout << go(l) << '\n';
	}
	return 0;
}
