#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
using namespace std;
typedef long long ll;
const int MAX_N = 15;
int n, k, len[MAX_N + 1], a[MAX_N + 1], mt[51];
string s[MAX_N + 1];
ll dp[101][1 << MAX_N];

ll gcd(ll p, ll q) {
	if (q == 0) return p;
	return gcd(q, p % q);
}

ll go(int m, int v) {
	if (v == (1 << n) - 1) {
		if (m == 0) return 1;
		return 0;
	}
	ll &ret = dp[m][v];
	if (ret != -1) return ret;
	
	ret = 0;
	for (int i = 0; i < n; i++) {
		if (v & (1 << i)) continue;
		int nxt = (m * mt[len[i]] + a[i]) % k;
		ret += go(nxt, v | (1 << i));
	}
	
	return ret;
}
int main() {
	fio();
	memset(dp, -1, sizeof(dp));
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i];
	cin >> k;
	
	mt[0] = 1;
	for (int i = 1; i < 51; i++) 
		mt[i] = mt[i - 1] * 10 % k;
	
	for (int i = 0; i < n; i++) {
		int m = 0;
		len[i] = s[i].length();
		for (int j = len[i] - 1; j >= 0; j--) {
			m += (s[i][j] - '0') * mt[len[i] - 1 - j] % k;
			m %= k;
		}
		a[i] = m;
	}
	
	ll p = go(0, 0), q = 1;
	for (int i = 1; i <= n; i++) q *= i;
	
	if (p == 0) cout << "0/1" << '\n';
	else {
		ll g = gcd(p, q);
		cout << p / g << '/' << q / g << '\n';
	}
	return 0;
}
