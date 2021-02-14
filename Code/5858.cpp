#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define ends " "
#define pb(x) push_back(x)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define fileio() ifstream file_in("input.txt");ofstream file_out("output.txt")
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tpi;
typedef tuple<ll, ll, ll> tpl;
typedef pair<double, ll> pdl;
typedef pair<double, int> pdi;
const int MOD = 1000000007; // PLZ check
const ll LMOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1);
const double eps = 1e-10;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int MAXN = 1e5 + 10;

vector<pii> a;
vector<int> b;
int idx(int x) {
	return lower_bound(all(b), x) - b.begin();
}
int main() {
	fio();

	int n, cur = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x; char c;
		cin >> x >> c;
		if (c == 'R') {
			a.push_back({cur, cur + x});
			b.pb(cur), b.pb(cur + x);
			cur += x;
		}
		else {
			a.push_back({cur - x, cur});
			b.pb(cur), b.pb(cur - x);
			cur -= x;
		}
	}
	sort(all(b)), b.erase(unique(all(b)), b.end());

	int d[MAXN] = { 0 }; ll ans = 0;
	for (auto p : a) d[idx(p.first)]++, d[idx(p.second)]--;
	for (int i = 1; i < b.size(); i++) d[i] += d[i - 1];
	for (int i = 0; i < b.size() - 1; i++) 
		if (d[i] >= 2) ans += b[i + 1] - b[i];

	cout << ans << '\n';
	return 0;
}
