#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define fileio() ifstream file_in("input.txt");ofstream file_out("output.txt")
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
const int MAXN = 1e5 + 10;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	fio();
	int n;
	cin >> n;

	vector<pair<pll, int>> a;
	
	for (int i = 0; i < n; i++) {
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		ll g1 = gcd(x1, y1), g2 = gcd(x2, y2);
		x1 /= g1, y1 /= g1, x2 /= g2, y2 /= g2;
		if (x1*y2 < x2*y1) {
			a.push_back({{y2, x2}, 1});
			a.push_back({{y1, x1}, -1});
		}
		else {
			a.push_back({{y1, x1}, 1});
			a.push_back({{y2, x2}, -1});
		}
	}
	sort(all(a), [](auto a, auto b) {
		return a.f.f * b.f.s < a.f.s * b.f.f;});

	int p = 0;
	ll ans = 0, k = 0;
	while (p < a.size()) {
		auto c = a[p];
		ll mc = 0;
		while (p < a.size() && a[p].f == c.f) {
			if (a[p].s == -1) ++mc;
			else ++k;
			++p;
		}
		ans = max(ans, k);
		k -= mc;
	}

	cout << ans << '\n';
	return 0;
}
