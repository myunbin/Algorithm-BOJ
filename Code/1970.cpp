#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1001;
int dp[MAX_N][MAX_N], a[MAX_N];
int n;

int go(int i, int j) {
	if (i > j) return 0;
	
	int &ret = dp[i][j];
	if (ret != -1) return ret;
	
	ret = go(i + 1, j);
	for (int k = i + 1; k <= j; k++) {
		if (a[i] == a[k])
			ret = max(ret, go(i + 1, k - 1) + go(k + 1, j) + 1);
	}
	
	return ret;
}
int main(){
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);
	
	memset(dp, -1, sizeof(dp));
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	
	cout << go(0, n - 1) << '\n';
	
    return 0;
}
