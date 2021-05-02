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
const int MAXN = 1010;
const int MAXR = 2e5 + 10;
int n, m;
ll dp[MAXN][MAXN];
vector<ll> a, b;

ll go(int i, int j) {
	if (i == min(n, m)) return 0;
	ll &ret = dp[i][j];
	if (ret != -1) return ret;
	ret = LINF;
	for (int k = j; k < max(n, m); k++) 
		ret = min(ret, go(i+1, k+1)+abs(a[i]-b[k]));
	return ret;
}
int main() {
	fio();
	memset(dp, -1, sizeof(dp));
	cin >> n >> m;
	a.resize(min(n, m)), b.resize(max(n, m));
	vector<ll> t1(n), t2(m);
	for (int i = 0; i < n; i++) cin >> t1[i];
	for (int i = 0; i < m; i++) cin >> t2[i];
	if (n < m) a = t1, b = t2;
	else a = t2, b = t1;
	sort(all(a)), sort(all(b));
	cout << go(0, 0) << endl;

	return 0;
}
