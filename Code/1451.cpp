#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 101;
int n, m;
ll p[MAX_N][MAX_N];

ll sum(int x1, int y1, int x2, int y2) {
	return p[x2][y2] - p[x2][y1 - 1] - p[x1 - 1][y2] + p[x1 - 1][y1 - 1];
}

void solve() {
	ll ans = 0;
    for (int i = 1; i <= m - 2; i++) {
        for (int j = i + 1; j <= m - 1; j++) {
            ll tmp1 = sum(1, 1, n, i);
            ll tmp2 = sum(1, i + 1, n, j);
            ll tmp3 = sum(1, j + 1, n, m);
            ans = max(ans, tmp1 * tmp2 * tmp3);
        }
    }
	for (int i = 1; i <= n - 2; i++) {
		for (int j = i + 1; j <= n - 1; j++) {
			ll tmp1 = sum(1, 1, i, m);
			ll tmp2 = sum(i + 1, 1, j, m);
			ll tmp3 = sum(j + 1, 1, n, m);
			ans = max(ans, tmp1 * tmp2 * tmp3);
		}
	}
    for (int i = 1; i <= n - 1; i++) {
		for (int j = 1; j <= m - 1; j++) {
			ll tmp1, tmp2, tmp3;
			tmp1 = sum(1, 1, n, j);
			tmp2 = sum(1, j + 1, i, m);
			tmp3 = sum(i + 1, j + 1, n , m);
			ans = max(ans, tmp1 * tmp2 * tmp3);
			
			tmp1 = sum(1, 1, i, j);
			tmp2 = sum(i + 1, 1, n, j);
			tmp3 = sum(1, j + 1, n, m);
			ans = max(ans, tmp1 * tmp2 * tmp3);
			
			tmp1 = sum(1, 1, i, m);
			tmp2 = sum(i + 1, 1, n, j);
			tmp3 = sum(i + 1, j + 1, n, m);
			ans = max(ans, tmp1 * tmp2 * tmp3);
			
			tmp1 = sum(1, 1, i, j);
			tmp2 = sum(1, j + 1, i, m);
			tmp3 = sum(i + 1, 1, n, m);
			ans = max(ans, tmp1 * tmp2 * tmp3);
		}
	}
    
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) {
			p[i][j + 1] = p[i - 1][j + 1] + p[i][j] - p[i - 1][j];
			p[i][j + 1] += s[j] - '0';
		}
	}
	
	solve();

    return 0;
}
