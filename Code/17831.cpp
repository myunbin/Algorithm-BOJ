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
const int MOD = 1000000007; // PLZ check
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 2e5 + 10;
const int MAXR = 2e5 + 10;

vector<int> child[MAXN];
int n, a[MAXN], dp[MAXN][2];

int go(int cur, bool b) {
	int &ret = dp[cur][b];
	if (ret != -1) return ret;

	int s = 0;
	for (int nxt : child[cur]) s += go(nxt, false);
	ret = s;
	if (!b) {
		for (int nxt : child[cur]) {
			int c = s - go(nxt, false) + go(nxt, true) + a[cur] * a[nxt];
			ret = max(ret, c);
		}
	}
	return ret;
}

int main() {
	fio();
	memset(dp, -1, sizeof(dp));

	cin >> n;
	for (int i = 2; i <= n; i++) {
		int x; cin >> x;
		child[x].pb(i);
	}
	for (int i = 1; i <= n; i++) cin >> a[i];

	cout << go(1, 0) << endl;

	return 0;
}
