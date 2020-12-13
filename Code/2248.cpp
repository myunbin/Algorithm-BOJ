#include <bits/stdc++.h>
using namespace std;
int dp[31][31];
char ans[31];
int N, L, I;

int solve(int n, int l) {
	int &ret = dp[n][l];
	if (ret != -1) return ret;
	
	if (n == 0 || l == 0) return ret = 1;
	
	return ret = solve(n - 1, l) + solve(n - 1, l - 1);
}

void findAns(int n, int m, int k, int p){
	if (n == 0) return;
	if (m == 0) {
		for (int i = 0; i < n; i++) 
			ans[p + i] = '0';
	}
	
	int pivot = solve(n - 1, m);
	if (k <= pivot) {
		ans[p] = '0';
		findAns(n - 1, m, k, p + 1);
	}
	else {
		ans[p] = '1';
		findAns(n - 1, m - 1, k - pivot, p + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);
	
	memset(dp, -1, sizeof(dp));
	
	cin >> N >> L >> I;
  	solve(N, L);
	findAns(N, L, I, 0);
	
	cout << ans << '\n';

  	return 0;
}
