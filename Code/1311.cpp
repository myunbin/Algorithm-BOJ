#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
using namespace std;
typedef pair<int, int> pii;
const int MAX_N = 20;
const int INF = 2e9;
int n, dp[MAX_N][1 << MAX_N], c[MAX_N][MAX_N];

int go(int i, int v) {
	if (i == n || v == (1 << n) - 1) return 0;
	int &ret = dp[i][v];
	if (ret != -1) return ret;

	ret = INF;
	for (int j = 0; j < n; j++) {
		if (v & (1 << j)) continue;
		ret = min(ret, go(i + 1, v | (1 << j)) + c[i][j]);
	}
	return ret;
}

int main() {
	fio();
	memset(dp, -1, sizeof(dp));
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> c[i][j];
	}

	cout << go(0, 0) << '\n';
	return 0;
}
