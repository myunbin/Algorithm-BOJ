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
const int MOD = 1234567891;
const ll LMOD = 1e9+7; // PLZ check
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 555;
const int MAXR = 2e5 + 10;
int n, m, b, a[MAXN][MAXN];
int solve(int h) {
	int tb = b, ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] > h) {
				tb += a[i][j]-h;
				ret += (a[i][j]-h)*2;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] < h) {
				tb += a[i][j]-h;
				ret += (h-a[i][j]);
			}
		}
	}
	if (tb < 0) return -1;
	return ret;
}

int main() {
	fio();
	cin >> n >> m >> b;
	int lo = INF, hi = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			lo = min(lo, a[i][j]);
			hi = max(hi, a[i][j]);
		}
	}

	int ans = INF, ansh;
	for (int h = hi; h >= lo; h--) {
		int t = solve(h);
		if (t != -1 && ans > t) {
			ans = t;
			ansh = h;
		}
	}
	cout << ans << ' ' << ansh << endl;
	return 0;
}
