#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define pb(x) push_back(x)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define fileio() ifstream file_in("boards.txt");ofstream file_out("boards.txt")
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
const int MOD = 987654321;
const ll LMOD = 1e9+7; // PLZ check
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 200;
const int MAXR = 2e5 + 10;

int n, m, dp[22][22][22], a[22];
int go(int i, int l, int r) {
	if (i == m) return 0;
	int &ret = dp[i][l][r];
	if (ret != -1) return ret;

	int cl = abs(a[i]-l), cr = abs(a[i]-r);
	return ret = min(cl + go(i+1, a[i], r), cr + go(i+1, l, a[i]));
}
int main() {
	fio();
	memset(dp, -1, sizeof(dp));

	int l, r;
	cin >> n >> l >> r >> m;
	for (int i = 0; i < m; i++) cin >> a[i];
	cout << go(0, l, r) << endl;
	return 0;
}

