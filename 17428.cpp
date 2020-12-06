#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 55;

ll dp[MAX_N][MAX_N];
ll N, K;

ll go(ll n, ll m) {
	ll &ret = dp[n][m];
	if (ret != -1) return ret;
	if (n == N) return ret = (m == 0);
	
	ret = go(n + 1, m + 1);
	if (m > 0) ret += go(n + 1, m - 1);
	
	return ret;
}

vector<char> ans;
void trackAns(ll n, ll m, ll k) {
	if (n == N) return;
	
	ll pivot = go(n + 1, m + 1);
	if (k <= pivot) {
		ans.push_back('(');
		trackAns(n + 1, m + 1, k);
	}
	else {
		ans.push_back(')');
		trackAns(n + 1, m - 1, k - pivot);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);

	memset(dp, -1, sizeof(dp));
	cin >> N >> K;
	
	K++;
	go(0, 0);
	trackAns(0, 0, K);
	
	if (go(0, 0) < K) cout << -1;
	else for (char c : ans) cout << c;
	cout << '\n';
	return 0;
}
