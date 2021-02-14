#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define ends " "
#define pb(x) push_back(x)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define fileio() ifstream file_in("hayfeast.in");ofstream file_out("hayfeast.out")
#define double long double
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tpi;
typedef tuple<ll, ll, ll> tpl;
typedef pair<double, ll> pdl;
const int MOD = 1000000007; // PLZ check
const ll LMOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1);
const double eps = 1e-10;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int MAX_N = 2e5 + 10;

int main() {
	fio();
	
	int n, k;
	cin >> n >> k;

	map<int, int> m;
	int a[MAX_N] = { 0 }, p[MAX_N] = { 0 };

	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		p[i] += p[i - 1] + a[i];
		if (p[i] == k) ans++;
		ans += 1LL*m[p[i] - k];
		m[p[i]]++;
	}
	
	cout << ans << '\n';
	return 0;
}
