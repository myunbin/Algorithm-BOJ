#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define pb(x) push_back(x)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define fileio() ifstream file_in("boards.txt");ofstream file_out("boards.txt")
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

int n, k, dp[MAXN][MAXN*1010];
pii a[MAXN];

int go(int i, int c) {
	if (i == n) return 0;
	int &ret = dp[i][c];
	if (ret != -1) return ret;
	ret = go(i+1, c);
	if (c-a[i].f >= 0) ret = max(ret, go(i+1, c-a[i].f)+a[i].s);
	return ret;
}

int main() {
	fio();
	memset(dp, -1, sizeof(dp));

	cin >> n >> k;
	for (int i = 0; i < n; i++) 
		cin >> a[i].f >> a[i].s;
	cout << go(0, k) << endl;
	return 0;
}

