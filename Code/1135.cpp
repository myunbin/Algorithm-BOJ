#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define ppb(x, y) push_back({x, y})
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 2e9;
const int MAX_N = 51;
vector<int> adj[MAX_N];
int n, dp[MAX_N];

int go(int i) {
	if (adj[i].empty()) return 0;

	int &ret = dp[i];
	if (ret != -1) return ret;

	vector<int> t;
	for (int j : adj[i]) t.pb(go(j));
	sort(all(t), greater<int>());

	int cnt = 1;
	for (int x : t) {
		ret = max(ret, cnt + x);
		cnt++;
	}

	return ret;
}

int main() {
	fio();
	memset(dp, -1, sizeof(dp));

	cin >> n;
	for (int i = 0; i < n; i++) {
		int u; cin >> u;
		if (u == -1) continue;
		adj[u].pb(i);
	}

	cout << go(0) << '\n';

	return 0;
}
