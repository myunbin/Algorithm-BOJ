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
const int MAXN = 1e3 + 10;
const int MAXR = 2e5 + 10;
int dp[MAXN][MAXN];
string a, b;
int go(int i, int j) {
	if (i == a.size()) return b.size() - j;
	if (j == b.size()) return a.size() - i;
	int &ret = dp[i][j];
	if (ret != -1) return ret;

	if (a[i] == b[j]) return ret = go(i+1, j+1);
	return ret = 1 + min({go(i+1, j), go(i, j+1), go(i+1, j+1)});
}

int main() {
	fio();
	memset(dp, -1, sizeof(dp));
	cin >> a >> b;
	cout << go(0, 0) << endl;
	return 0;
}

