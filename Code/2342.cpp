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
const int MAX_N = 1e5 + 1;
const int INF = 1e9;
int dp[5][5][MAX_N], n;
vector<int> a;

int go(int x, int y, int i) {
	if (i == n) return 0;

	int &ret = dp[x][y][i];
	if (ret != -1) return ret;

	ret = INF;
	if (x == a[i] || y == a[i]) return ret = 1 + go(x, y, i + 1);
	
	int c;
	
	if (x == 0) c = 2;
	else if (abs(x - a[i]) == 2) c = 4;
	else c = 3;

	ret = min(ret, c + go(a[i], y, i + 1));

	if (y == 0) c = 2;
	else if (abs(y - a[i]) == 2) c = 4;
	else c = 3;

	ret = min(ret, c + go(x, a[i], i + 1)); 

	return ret;
}

int main() {
	fio();
	memset(dp, -1, sizeof(dp));

	for (int i = 0;; i++) {
		int x; cin >> x;
		if (x == 0) break;
		a.pb(x);
	}

	n = a.size();
	
	cout << go(0, 0, 0) << '\n';
		
	return 0;
}
