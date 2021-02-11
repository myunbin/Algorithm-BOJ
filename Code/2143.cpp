#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define ppb(x, y) push_back({x, y})
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tp;
const int MAX_N = 1e5;
const int INF = 2e9;

int main() {
	fio();

	int n, m, t;
	cin >> t;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		a[i] = a[i - 1] + x;
	}
	cin >> m;
	vector<int> b(m + 1);
	for (int i = 1; i <= m; i++) {
		int x; cin >> x;
		b[i] = b[i - 1] + x;
	}

	vector<int> sa, sb;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++)
			sa.pb(a[j] - a[i - 1]);
	}
	for (int i = 1; i <= m; i++) {
		for (int j = i; j <= m; j++) 
			sb.pb(b[j] - b[i - 1]);
	}

	sort(all(sa)), sort(all(sb));
	int asz = sa.size(), bsz = sb.size();
	ll ans = 0;

	for (int i = 0; i < asz; i++) 
		ans += upper_bound(all(sb), t - sa[i]) - lower_bound(all(sb), t - sa[i]);
	
	cout << ans << '\n';
	
	return 0;
}
