#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 110;
const int INF = 1e9;
int dp[MAX_N][MAX_N];
char ans[MAX_N * 2];
int N, M, K;
bool flag = true;

int go(int n, int m) {
	int &ret = dp[n][m];
	if (ret != -1) return ret;
	if (n == 0 || m == 0) return ret = 1;
	return ret = min(go(n - 1, m) + go(n, m - 1), INF + 1);
}

void trackAns(int pos, int n, int m, int k) {
	if (n == 0) {
		for (int i = 0; i < m; i++)
			ans[pos + i] = 'z';
		return;
	}
	if (m == 0) {
		for (int i = 0; i < n; i++)
			ans[pos + i] = 'a';
		return;
	}
	
	int pivot = go(n - 1, m);

	if (k <= pivot) {
		ans[pos] = 'a';
		trackAns(pos + 1, n - 1, m, k);
	}
	else if (pivot <= INF){
		ans[pos] = 'z';
		trackAns(pos + 1, n, m - 1, k - pivot);
	}
	else flag = false;
}

int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);
	
	memset(dp, -1, sizeof(dp));
	cin >> N >> M >> K;
	
	if (go(N, M) < K) flag = false;
	else trackAns(0, N, M, K);
	
	if (flag) cout << ans << '\n';
	else cout << -1 << '\n';
	
	return 0;
}
