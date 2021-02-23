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
const int MAXN = 1010;
const int MAXR = 2e5 + 10;
int n, a[MAXN][3], dp[MAXN][3][3];

int go(int i, int l, int f) {
	if (i == n) return 0;
	int &ret = dp[i][l][f];
	if (ret != -1) return ret;

	ret = INF;
	if (i == 0) {
		for (int j = 0; j < 3; j++) {
			ret = min(ret, a[i][j] + go(i+1, j, j));
		}
	}
	else if (i == n-1) {
		for (int j = 0; j < 3; j++) {
			if (j != l && j != f) ret = min(ret, a[i][j] + go(i+1, j, f));
		}
	}
	else {
		for (int j = 0; j < 3; j++) {
			if (j != l) ret = min(ret, a[i][j] + go(i+1, j, f));
		}
	}
	return ret;
}
int main() {
	fio();
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < 3; j++) cin >> a[i][j];
	cout << go(0,0,0) << endl;
	return 0;
}

