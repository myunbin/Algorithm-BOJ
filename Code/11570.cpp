#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define fileio() ifstream file_in("input.txt");ofstream file_out("output.txt")
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tpi;
typedef tuple<ll, ll, ll> tpl;
typedef pair<double, ll> pdl;
typedef pair<double, int> pdi;
const int MOD = 1000000007; // PLZ check
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 2020;
int n;
ll dp[MAXN][MAXN], a[MAXN];

ll go(int i, int j) {
	if (i == n || j == n) return 0;
	ll &ret = dp[i][j];
	if (ret != -1) return ret;
	
	int nxt = max(i, j) + 1;
	ll ci = (i == 0) ? 0 : abs(a[nxt] - a[i]);
	ll cj = (j == 0) ? 0 : abs(a[nxt] - a[j]);
	return ret = min(go(nxt, j) + ci, go(i, nxt) + cj);
}

int main() {
	fio();
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	cout << go(0, 0) << '\n';
	return 0;
}
