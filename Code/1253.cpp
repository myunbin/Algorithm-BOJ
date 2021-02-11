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
const int MAX_N = 2020;

int main() {
	fio();
	int n;
	cin >> n;
	vector<ll> a(n);
	bool c[MAX_N] = { false };
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(all(a));
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			ll s = a[i] + a[j];
			int idx = lower_bound(all(a), s) - a.begin();
			int idx2 = upper_bound(all(a), s) - a.begin();
			if (a[idx] == s && idx != i && idx != j) {
				for (int k = idx; k < idx2; k++) c[k] = true;	
			}
		}
	}
	for (int i = 0; i < n; i++) if (c[i]) ++ans;
	cout << ans << '\n';
	return 0;
}
