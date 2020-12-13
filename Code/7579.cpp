#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 101;
const int INF = 2e9;
int N, M;
int c[MAX_N], m[MAX_N];
int dp[MAX_N * MAX_N][MAX_N];
int ans = INF;

int go(int cost, int i) {
	if (i == N) return 0;
	
	int &ret = dp[cost][i];
	if (ret != -1) return ret;
	
	ret = go(cost, i + 1);
	
	if (cost - c[i] >= 0)
		ret = max(ret, go(cost - c[i], i + 1) + m[i]);
	
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);

	memset(dp, -1, sizeof(dp));

	cin >> N >> M;
	
	int sum = 0;
	for (int i = 0; i < N; i++) cin >> m[i];
	for (int i = 0; i < N; i++) {
		cin >> c[i];
		sum += c[i];
	}
	
	go(sum, 0);
	
	for (int c = 0; c <= sum; c++) {
		if (go(c, 0) >= M) {
			cout << c << '\n';
			return 0;
		}
	}
}
