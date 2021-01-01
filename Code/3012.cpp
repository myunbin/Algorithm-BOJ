#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 201;
const int MOD = 1e5;
ll dp[MAX_N][MAX_N];
int n;
string s;

ll go(int i, int j) {
	if (i > j) return 1LL;
	
	ll &ret = dp[i][j];
	if (ret != -1) return ret;
	
	ret = 0;
	for (int k = i + 1; k <= j; k++) {
		if (s[i] == '(') {
			if (s[k] == '?' || s[k] == ')') {
				ret += go(i + 1, k - 1) * go(k + 1, j);
			}
		}
		else if (s[i] == '{') {
			if (s[k] == '?' || s[k] == '}') {
				ret += go(i + 1, k - 1) * go(k + 1, j);
			}
		}
		else if (s[i] == '[') {
			if (s[k] == '?' || s[k] == ']') {
				ret += go(i + 1, k - 1) * go(k + 1, j);
			}
		}
		else if (s[i] == '?') {
			if (s[k] == '?') {
				ret += 3 * go(i + 1, k - 1) * go(k + 1, j);
			}
			else if (s[k] == ')' || s[k] == '}' || s[k] == ']') {
				ret += go(i + 1, k - 1) * go(k + 1, j);
			}
		}
		
		if (ret >= MOD) ret = MOD + ret % MOD;
	}
	
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);
	
	memset(dp, -1LL, sizeof(dp));
	
	cin >> n >> s;
	
	if (go(0, n - 1) >= MOD) printf("%05lld\n", go(0, n - 1) % MOD);
	else printf("%lld\n", go(0, n - 1));
    return 0;
}
