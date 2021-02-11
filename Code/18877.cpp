#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define ppb(x, y) push_back({x, y})
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tp;
const int MAX_N = 2e6 + 1;
const int INF = 2e9;
vector<pii> a;
int n, m;

bool f(int x) {
	int cnt = 0, i = 0;
	ll cur = a[0].first;
	while (i < m) {
		ll s = a[i].first, e = a[i].second;
		if (cur < s) {
			cur = s + x;
			cnt++;
		}
		while (s <= cur && cur <= e) {
			cnt++;
			cur += x;
		}
		i++;
	}
	return cnt >= n;
}

int main() {
	fio();

	cin >> n >> m;
	a.resize(m);
	for (int i = 0; i < m; i++) cin >> a[i].first >> a[i].second;
	sort(all(a));

	ll le = 0, ri = a[m - 1].second - a[0].first, ans = 0;
	while (le <= ri) {
		ll mid = le + ri >> 1;
		if (f(mid)) {
			ans = mid;
			le = mid + 1;
		}
		else ri = mid - 1;
	}

	cout << ans << '\n';
	return 0;
}
