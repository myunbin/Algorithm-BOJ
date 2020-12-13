#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 51;
ll dp[MAX_N][MAX_N * 2][2];
ll N, K;

ll go(ll n, ll m, bool minus) {
	ll &ret = dp[n][m + 50][minus];
	if (ret != -1) return ret;
	if (n == N) return ret = ((m != 0) || minus);
	
	return ret = go(n + 1, m + 1, minus) + go(n + 1, m - 1, (m - 1 < 0 || minus));
}

vector<char> ans;

void trackAns(ll n, ll m, bool minus, ll k) {
	if (n == N) return;
	
	ll pivot = go(n + 1, m + 1, minus);
	
	if (k <= pivot) {
		ans.push_back('(');
		trackAns(n + 1, m + 1, minus, k);
	}
	else {
		ans.push_back(')');
		trackAns(n + 1, m - 1, (minus || m - 1 < 0), k - pivot);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);

	memset(dp, -1, sizeof(dp));
	cin >> N >> K;
	K++;
		
	if (go(0, 0, false) < K) cout << -1;
	else {
		trackAns(0, 0, false, K);
		for (char c : ans) cout << c;	
	}
	cout << '\n';
	
	return 0;
}
