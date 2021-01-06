#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int MAX_N = 1001;
int n, w;
int dp[MAX_N][MAX_N];
vector<pii> a;

int go(int i, int j) {
	if (i == w || j == w) return 0;

	int &ret = dp[i][j];
	if (ret != -1) return ret;
	
	int idx = max(i, j) + 1;
	pii nxt = a[idx];
	
	int dist_i = abs(a[i].first - nxt.first) + abs(a[i].second - nxt.second);
	int dist_j = abs(a[j].first - nxt.first) + abs(a[j].second - nxt.second);
	if (i == 0) dist_i = nxt.first + nxt.second - 2;
	if (j == 0) dist_j = 2 * n - (nxt.first + nxt.second);
	
	return ret = min(go(idx, j) + dist_i, go(i, idx) + dist_j);
}

void trackAns(int i, int j) {
	if (i == w || j == w) return;
	
	int idx = max(i, j) + 1;
	pii nxt = a[idx];
	
	int dist_i = abs(a[i].first - nxt.first) + abs(a[i].second - nxt.second);
	int dist_j = abs(a[j].first - nxt.first) + abs(a[j].second - nxt.second);
	if (i == 0) dist_i = nxt.first + nxt.second - 2;
	if (j == 0) dist_j = 2 * n - (nxt.first + nxt.second);
	
	if (go(idx, j) + dist_i < go(i, idx) + dist_j) {
		cout << 1 << '\n';
		trackAns(idx, j);
	}
	else {
		cout << 2 << '\n';
		trackAns(i, idx);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);
	
	memset(dp, -1, sizeof(dp));
	cin >> n >> w;
	a.resize(w + 1);
	for (int i = 1; i <= w; i++) 
		cin >> a[i].first >> a[i].second;
	
	cout << go(0, 0) << '\n';
	trackAns(0, 0);
	return 0;
}
