#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 33;
int N;
int dp[MAX_N * 500][MAX_N];
int m[MAX_N];

int go(int d, int i) {
	if (d == 0) return true;
	if (i == N) return false;
	
	int &ret = dp[d][i];
	if (ret != -1) return ret;
	
	ret = go(d + m[i], i + 1) || go(abs(d - m[i]), i + 1) || go(d, i + 1);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);

	memset(dp, -1, sizeof(dp));
	
	cin >> N;
	for (int i = 0; i < N; i++) cin >> m[i];
	
	int t;
	cin >> t;
	while (t--) {
		int x;
		cin >> x;
		
		if (x > 30 * 500) {
			cout << "N ";
			continue;
		}
		
		int ans = go(x, 0);
		if (ans) cout << "Y ";
		else cout << "N ";
	}
	
	return 0;
}
