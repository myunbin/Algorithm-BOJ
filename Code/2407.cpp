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

string dp[111][111];

string pl(string a, string b) {
	string ret;
	int sum = 0;
	while (sum || !a.empty() || !b.empty()) {
		if (!a.empty()) {
			sum += a.back()-'0';
			a.pop_back();
		}
		if (!b.empty()) {
			sum += b.back()-'0';
			b.pop_back();
		}
		ret += sum%10+'0';
		sum /= 10;
	}
	reverse(all(ret));
	return ret;
}

string go(int n, int r) {
	if (n == r || r == 0) return "1";
	string &ret = dp[n][r];
	if (ret != "") return ret;
	return ret = pl(go(n-1, r-1), go(n-1, r));
}

int main() {
	fio();
	int n, m;
	
	cin >> n >> m;
	//cout << pl("0", "0") << endl;
	cout << go(n, m) << endl;
	return 0;
}
