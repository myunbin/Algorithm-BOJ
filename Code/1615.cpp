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
const int MOD = 1000000007;
const ll LMOD = 1e9+7; // PLZ check
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 2020;
const int MAXR = 2e5 + 10;

vector<ll> tr;
int n, m;

void update(int i, ll v) {
	for (; i <= n; i += (i & -i)) tr[i] += v; 
}

ll query(int i, ll s = 0) {
	for (; i > 0; i -= (i & -i)) s += tr[i];
	return s;
}


int main() {
	fio();
	cin >> n >> m;
	tr.resize(n+1, 0);
	vector<pii> a(m);
	for (int i = 0; i < m; i++) 
		cin >> a[i].f >> a[i].s;
	sort(all(a));

	ll ans = 0;
	for (auto [x, y] : a) {
		ans += query(n) - query(y);
		update(y, 1);
	}

	cout << ans << endl;
	return 0;
}

