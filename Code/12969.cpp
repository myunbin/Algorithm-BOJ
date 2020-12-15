#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 31;
int dp[MAX_N][MAX_N][MAX_N][MAX_N * MAX_N / 2];
int N, K;
vector<char> ans;

int go(int n, int a, int b, int k) {
	if (n == N) {
		if (k == K) 
			return true;	
		return false;
	}
	
	int &ret = dp[n][a][b][k];
	if (ret != -1) return ret;
	
	ret = false;
	
	ans.push_back('A');
	if (go(n + 1, a + 1, b, k)) return ret = true;
	ans.pop_back();
	
	ans.push_back('B');
	if (go(n + 1, a, b + 1, k + a)) return ret = true;
	ans.pop_back();
	
	ans.push_back('C');
	if (go(n + 1, a, b, k + a + b)) return ret = true;
	ans.pop_back();
	
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);

	memset(dp, -1, sizeof(dp));
	cin >> N >> K;
	
	if (go(0, 0, 0, 0)) {
		for (char c : ans) cout << c;
	}
	else cout << -1;
	
	return 0;
}
