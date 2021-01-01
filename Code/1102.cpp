#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 17;
const int INF = 1e9;
int w[MAX_N][MAX_N], dp[1 << 16][MAX_N];
int n, p, cnt;
string s;

int go(int v, int k) {
	if (k >= p - cnt) return 0;
	
	int &ret = dp[v][k];
	if (ret != -1) return ret;
	
	ret = INF;
	for (int i = 0; i < n; i++) {
		if (v & (1 << i)) {
			for (int j = 0; j < n; j++) {
				if (!(v & (1 << j))) {
					ret = min(ret, go(v | (1 << j), k + 1) + w[i][j]);	
				}
			}
		}
	}
	
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);
	
	memset(dp, -1, sizeof(dp));

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> w[i][j];
	}
	
	cin >> s;
	int v = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'Y') {
			v |= (1 << i);
			cnt++;
		}
	}
	
	cin >> p;
	
	if (p == 0) cout << 0 << '\n';
	else {
		int ans = go(v, 0);
		if (ans == INF) cout << -1 << '\n';
		else cout << ans << '\n';
	}
    return 0;
}
