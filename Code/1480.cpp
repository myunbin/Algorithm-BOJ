#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
using namespace std;
int n, m, c;
int dp[14][21][1 << 13], a[14];
int go(int i, int k, int v) {
	if (i == m || v == (1 << n) - 1) return 0;
	
	int &ret = dp[i][k][v];
	if (ret != -1) return ret;
	
	ret = go(i + 1, c, v);
	for (int j = 0; j < n; j++) {
		if (v & (1 << j)) continue;	
		if (k - a[j] >= 0) ret = max(ret, go(i, k - a[j], v | (1 << j)) + 1);
	}
	
	return ret;
}
int main() {
	fio();
	
	memset(dp, -1, sizeof(dp));
	cin >> n >> m >> c;
	for (int i = 0; i < n; i++) cin >> a[i];
	
	cout << go(0, c, 0) << '\n';
	return 0;
}
