#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 101;
const int MOD = 1e9;
int n, dp[MAX_N][10][1 << 10];

int go(int i, int l, int v) {
	if (i == n) {
		if (v == (1 << 10) - 1) return 1;
		return 0;
	}
	
	int &ret = dp[i][l][v];
	if (ret != -1) return ret;
	
	ret = 0;
	if (l + 1 < 10) ret += go(i + 1, l + 1, v | 1 << (l + 1));
	if (l - 1 >= 0) ret += go(i + 1, l - 1, v | 1 << (l - 1));
	ret %= MOD;
	
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);
	memset(dp, -1, sizeof(dp));
	
	cin >> n;	
	
	int ans = 0;
	for (int i = 1; i <= 9; i++) {
		ans += go(1, i, (1 << i));
		ans %= MOD;
	}
	
	cout << ans << '\n';
    return 0;
}
