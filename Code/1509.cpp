#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
using namespace std;
typedef long long ll;
const int INF = 2e9;
const int MAX_N = 2001;
int n, l;
int dp[MAX_N][MAX_N];
string s;
int go(int i, int j) {
	if (i == j) return 1;
	if (i + 1 == j) {
		if (s[i] == s[j]) return 1;
		return 0;
	}
	
	int &ret = dp[i][j];
	if (ret != -1) return ret;
	
	if (s[i] != s[j]) return ret = 0;
	return ret = go(i + 1, j - 1);
}

int d[MAX_N];
int f(int i) {
	if (i == l) return 0;
	int &ret = d[i];
	if (ret != -1) return ret;
	
	ret = INF;
	for (int j = i; j < l; j++) 
		if (go(i, j)) ret = min(ret, f(j + 1) + 1);
	
	return ret;
}

int main() {
	fio();
	memset(dp, -1, sizeof(dp));
	memset(d, -1, sizeof(d));
	
	cin >> s;
	l = s.length();
	
	cout << f(0) << '\n';
	return 0;
}
