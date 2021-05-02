#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define pb(x) push_back(x)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define fileio() ifstream file_in("cowjump.in");ofstream file_out("cowjump.out")
#define f first
#define s second
#define double long double
#define db double
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tpi;
typedef tuple<ll, ll, ll> tpl;
typedef pair<double, ll> pdl;
typedef pair<double, int> pdi;
typedef pair<double, double> pdd;
const int MOD = 987654321;
const ll LMOD = 1e9+7; // PLZ check
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 111;
const int MAXR = 2e5 + 10;

int n, dp[MAXN][MAXN], a[MAXN];

int go(int i, int j) {
	if (i > j) return 0;
	int &ret = dp[i][j];
	if (ret != -1) return ret;

	ret = go(i+1, j);
	for (int k = i+1; k <= j; k++) {
		if (a[k] != 0 && a[i] == a[k]) {
			ret = max(ret, go(i+1, k-1)+go(k+1, j)+1);
		}
	}
	return ret;
}
int main() {
	fio();
	memset(dp, -1, sizeof(dp));

	cin >> n;
	int c = 1;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		a[x] = c, a[y] = c++;
	}

	cout << go(1, 100) << endl;
	return 0;
}
