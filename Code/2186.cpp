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
const int MAX_N = 101;
const int MOD = 1e9;
int n, m, k, dp[MAX_N][MAX_N][85];
string f, s[MAX_N];

struct t {int x, y, z;};
int dirx[] = {1, -1, 0, 0}, diry[] = {0, 0, 1, -1};

bool inMap(int x, int y) {
	if (0 <= x && x < n && 0 <= y && y < m) return true;
	return false;
}

int go(int x, int y, int z) {
	if (z == f.length() - 1) return 1;

	int &ret = dp[x][y][z];
	if (ret != -1) return ret;

	ret = 0;
	for (int i = 1; i <= k; i++) {
		for (int k = 0; k < 4; k++) {
			int nx = x + i * dirx[k], ny = y + i * diry[k];
			if (!inMap(nx, ny)) continue;

			if (s[nx][ny] == f[z + 1]) ret += go(nx, ny, z + 1);
		}
	}

	return ret;
}

int main() {
	fio();
	memset(dp, -1, sizeof(dp));
	
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) cin >> s[i];
	cin >> f;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == f[0]) ans += go(i, j, 0);
		}
	}

	cout << ans << '\n';
	return 0;
}
