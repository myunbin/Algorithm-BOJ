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
const int MAXN = 111;
const int MAXR = 2e5 + 10;
int n, m, dp[4000][4000];
string a, b;
int go(int i, int j) {
	if (i == n || j == m) return 0;
	int &ret = dp[i][j];
	if (ret != -1) return ret;

	if (a[i] == b[j]) ret = 1+go(i+1, j+1);
	return ret = max({ret, go(i+1, j), go(i, j+1)}); 
}

string ans;
void trk(int i, int j) {
	if (i == n || j == m) {
		cout << ans << endl;
		return;
	}
	if (a[i] == b[j]) {
		if (1+ans.size()+go(i+1, j+1) == go(0, 0)) {
			ans += a[i];
			trk(i+1, j+1);
		}
	}
	else {
		if (ans.size()+go(i+1, j) == go(0, 0)) trk(i+1, j);
		else trk(i, j+1);
	}
}

int main() {
	fio();
	memset(dp, -1, sizeof(dp));
	cin >> a >> b;
	n = a.size(), m = b.size();
	go(0, 0);
	trk(0, 0);
	return 0;
}
