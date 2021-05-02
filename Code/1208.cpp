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
const int MAXN = 555;
const int MAXR = 2e5 + 10;

void make(vector<ll> &ret, vector<ll> a) {
	int sz = a.size();
	for (int i = 1; i < (1<<sz); i++) {
		ll s = 0;
		for (int j = 0; j < sz; j++) if (i & (1<<j)) s += a[j]; 
		ret.pb(s);
	}
}

int main() {
	fio();

	int n; ll s;
	cin >> n >> s;
	
	vector<ll> t1, t2;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (i < n/2) t1.pb(x);
		else t2.pb(x);
	}

	vector<ll> a, b;
	make(a, t1), make(b, t2);
	sort(all(a)), sort(all(b));

	ll ans = 0;
	for (ll x : a) if (x == s) ans++;
	for (ll x : b) if (x == s) ans++;
	for (ll x : a) {
		int lo = lower_bound(all(b), s-x) - b.begin();
		int hi = upper_bound(all(b), s-x) - b.begin();
		if (x+b[lo] == s) ans += hi-lo;
	}

	cout << ans << endl;
	
	return 0;
}
