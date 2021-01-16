#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define ppb(x, y) push_back({x, y})
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MOD = 1e9 + 7;
const int MAX_N = 5005;
int dp[MAX_N][MAX_N];
string s;

int go(int x, int y) {
	if (y < 0 || y > s.length()) return 0;
	
	int &ret = dp[x][y];
	if (ret != -1) return ret;

	if (x == 0) {
		if (y == 0) return ret = 1;
		return ret = 0;
	}

	if (s[x - 1] == 'e') ret = (go(x - 1, y) % MOD + go(x, y + 1) % MOD) % MOD;
	else ret = go(x - 1, y - 1) % MOD;
	
	return ret;
}

int main() {
	fio();
	memset(dp, -1, sizeof(dp));
	cin >> s;

	int n = s.length();
	ll ans = 0; 
	for (int i = 0; i < n; i++) 
		ans = (ans + go(n - 1, i)) % MOD;
	cout << ans << '\n';
	return 0;
}
