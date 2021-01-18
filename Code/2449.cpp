#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define ppb(x, y) push_back({x, y})
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 2e9;
int dp[201][201], a[201];

int go(int i, int j) {
	if (i == j) return 0;
	int &ret = dp[i][j];
	if (ret != -1) return ret;

	ret = INF;
	for (int k = i + 1; k <= j; k++) {
		ret = min(ret, go(i, k - 1) + (a[i] != a[k]) + go(k, j));
	}
	return ret;
}

int main() {
	fio();
	memset(dp, -1, sizeof(dp));

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	
	cout << go(0, n - 1) << '\n';

	return 0;
}
