#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define pb(x) push_back(x)
#define ppb(x, y) push_back({x, y})
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n, dp[1001][1001], a[1001];

int go(int i, int j) {
	int p = (i + n - j - 1) % 2;
	if (i == j) {
		if (!p) return a[i];
		return 0;
	}

	int &ret = dp[i][j];
	if (ret != -1) return ret;

	if (!p) return ret = max(go(i + 1, j) + a[i], go(i, j - 1) + a[j]);  
	return ret = min(go(i + 1, j), go(i, j - 1));
}

int main() {
	fio();
	
	int t;
	cin >> t;
	while (t--) {
		memset(dp, -1, sizeof(dp));
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		cout << go(0, n - 1) << '\n';
	}
	return 0;
}
