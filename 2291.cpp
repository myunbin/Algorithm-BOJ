#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 11;
const int MAX_M = 222;

int dp[MAX_N][MAX_M][MAX_M];
int N, M, K;

int go(int n, int m, int l) {
	if (n == N) {
		if (m == 0) return 1;
		return 0;
	}
	
	int &ret = dp[n][m][l];
	if (ret != -1) return ret;
	
	ret = 0;
	for (int i = l; i <= M; i++) {
		if (m - i < 0) break;
		ret += go(n + 1, m - l, i);
	}
	
	return ret;
}

vector<int> ans;

void trackAns(int n, int m, int l, int k) {
	if (n == N) return;
	
	for (int i = l; i <= M; i++) {
		if (k > go(n, m, i)) k -= go(n, m, i);
		else {
			ans.push_back(i);
			trackAns(n + 1, m - i, i, k);
			break;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);
	
	memset(dp, -1, sizeof(dp));
	cin >> N >> M >> K;
	
	go(0, M, 1);
	trackAns(0, M, 1, K);
	
	for (int x : ans) cout << x << ' ';
	cout << '\n';
	
	return 0;
}
