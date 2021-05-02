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
const int MAXN = 101;
const int MAXR = 2e5 + 10;


int main() {
	fio();
	int t;
	cin >> t;

	int dp[15][15] = { 0 };
	for (int i=1; i<15; i++) dp[0][i] = i;
	for (int i=1; i<15; i++) {
		for (int j=1; j<15; j++) {
			dp[i][j] = dp[i][j-1]+dp[i-1][j];
		}
	}

	while (t--) {
		int k, n;
		cin >> k >> n;
		cout << dp[k][n] << endl;
	}
	return 0;
}
