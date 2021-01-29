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
const int MAX_N = 51;
const int INF = 1e9;
int n, m;
string s;
int a[MAX_N][MAX_N], cy[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];

bool v[MAX_N][MAX_N], f[MAX_N][MAX_N];
pii p[MAX_N][MAX_N];
int dirx[] = {1, -1, 0, 0}, diry[] = {0, 0, 1, -1};

bool inMap(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m) return false;
	return true;
}

void track(pii c, pii e) {
	cy[c.first][c.second] = -1;
	if (c == e) return;
	track(p[c.first][c.second], e);
}

void dfs(int x, int y) {
	v[x][y] = true;
	for (int k = 0; k < 4; k++) {
		int nx = x + a[x][y] * dirx[k], ny = y + a[x][y] * diry[k];
		if (!inMap(nx, ny) || a[nx][ny] == 0) continue;

		if (!v[nx][ny]) {
			p[nx][ny] = {x, y};
			dfs(nx, ny);
		}
		else if (!f[nx][ny]) {
			track({x, y}, {nx, ny});
		}
	}
	f[x][y] = true;
}

int go(int i, int j) {
	if (!inMap(i, j) || a[i][j] == 0) return 0;
	if (cy[i][j] < 0) return INF;

	int &ret = dp[i][j];
	if (ret != -1) return ret;

	for (int k = 0; k < 4; k++) {
		int ni = i + a[i][j] * dirx[k], nj = j + a[i][j] * diry[k];
		ret = max(ret, go(ni, nj) + 1);
	}
	
	return ret;
}

int main() {
	fio();
	memset(dp, -1, sizeof(dp));

	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == 'H') continue;
			a[i][j] = s[j] - '0';
		} 
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			p[i][j] = {-1, -1};
	}
	dfs(0, 0);

	int ans = go(0, 0);
	if (ans >= INF) cout << -1 << '\n';
	else cout << ans << '\n';

	return 0;
}
