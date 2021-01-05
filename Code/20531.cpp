#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 5005;
const int MOD = 1e9 + 7;
int p[MAX_N];
ll dp[MAX_N][MAX_N];
int n, m, g;

int find(int a) {
	if (p[a] < 0) return a;
	return p[a] = find(p[a]);
}

void merge(int a, int b) {
	a = find(a); b = find(b);
	if (a == b) return;
	g--; p[a] = b;
}

ll go(int n, int m) {
	if (n == m) return 1;
	if (m == 1) return 1;
	
	ll &ret = dp[n][m];
	if (ret != -1) return ret;
	
	return ret = (m * go(n - 1, m) + go(n - 1, m - 1)) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);
	
	memset(p, -1, sizeof(p));
	memset(dp, -1, sizeof(dp));
	
	cin >> n >> m;
	g = n;
	
	ll dp2[MAX_N] = { 0 };
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp2[i] += go(i, j);
			dp2[i] %= MOD;
		}
	}
	
	while (m--) {
		int x, y;
		cin >> x >> y;
		
		merge(x, y);
		
		cout << dp2[g] << '\n';
	}	
	return 0;
}
