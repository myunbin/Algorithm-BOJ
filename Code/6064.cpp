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
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}
void solve() {
	ll m, n, x, y;
	cin >> m >> n >> x >> y;
	ll g = gcd(m, n), l = m*n/g;
	for (ll i = 0; m*i+x <= l; i++) {
		ll t = m*i+x-y;
		if (t % n == 0) {
			cout << t+y << endl;
			return;
		}
	}
	cout << -1 << endl;
}

int main() {
	fio();
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}
