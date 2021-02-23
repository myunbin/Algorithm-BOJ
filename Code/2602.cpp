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
int ls, la;
string s, a[2];
int dp[22][110][2];

int go(int i, int j, int k) {
	if (i == ls) return 1;
	int &ret = dp[i][j][k];
	if (ret != -1) return ret;

	ret = 0;
	for (int p = j; p < la; p++) {
		if (a[k][p] == s[i]) 
			ret += go(i+1, p+1, !k);
	}

	return ret;
}
int main() {
	fio();
	memset(dp, -1, sizeof(dp));

	cin >> s >> a[0] >> a[1];
	ls = s.size(), la = a[0].size();

	cout << go(0, 0, 0) + go(0, 0, 1) << endl;
	return 0;
}

