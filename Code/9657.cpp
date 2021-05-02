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

int main() {
	fio();
	int n, dp[1010] = {0};
	cin >> n;
	dp[1] = 1, dp[2] = 0, dp[3] = 1, dp[4] = 1;
	for (int i = 5; i <= n; i++) dp[i] = !dp[i-1]||!dp[i-3]||!dp[i-4];
	cout << (dp[n]?"SK":"CY") << endl;
	return 0;
}
