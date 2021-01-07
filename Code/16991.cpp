#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
using namespace std;
typedef double db;
typedef pair<db, db> pii;
const int MAX_N = 16;
const db INF = (db)1e9;
vector<pii> a;
db dp[MAX_N][1 << MAX_N];
int n;

db dist(int i, int j) { 
	db dx = a[i].first - a[j].first;
	db dy = a[i].second - a[j].second;
	return sqrt(dx * dx + dy * dy);
}

db go(int i, int v) {
	if (v == (1 << n) - 1) return dist(i, 0);
	db &ret = dp[i][v];
	if (ret != -1) return ret;
	
	ret = INF;
	for (int k = 0; k < n; k++) {
		if (v & (1 << k)) continue;
		ret = min(ret, go(k, v | (1 << k)) + dist(i, k));
	}
	return ret;
}

int main() {
	fio();
	for (int i = 0; i < MAX_N; i++) 
		fill(dp[i], dp[i] + (1 << MAX_N), -1);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		a.push_back({x, y});
	}

	printf("%.9f\n", go(0, 1));
	
	return 0;
}
