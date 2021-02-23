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
const int MAXN = 1e4 + 10;
const int MAXR = 2e5 + 10;
int n;
ll dp[MAXN];

ll go(int i) {
	if (i == 2 || i == 0) return 1;
	ll &ret = dp[i];
	if (ret != -1) return ret;

	ret = 0;
	for (int j = 0; j < i; j += 2) {
		ret += go(j) * go(i-2-j);
		ret %= MOD;
	}
	return ret %= MOD;
}
int main() {
	fio();
	memset(dp, -1, sizeof(dp));

	cin >> n;
	cout << go(n) << endl;
	return 0;
}

