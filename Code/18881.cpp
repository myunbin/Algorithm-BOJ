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

int main() {
	fio();

	int n;
	cin >> n;
	vector<pii> a(n);
	vector<int> b;
	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
	sort(all(a));

	int r = INF;
	for (int i = 0; i < n; i++) {
		if (!a[i].second) {
			if (i > 0 && a[i - 1].second) r = min(r, a[i].first - a[i - 1].first);
			if (i < n - 1 && a[i + 1].second) r = min(r, a[i + 1].first - a[i].first);
		}
		else b.pb(a[i].first);
	}
	--r;

	int ans = 1;
	for (int i = 0; i < b.size() - 1; i++) {
		if (b[i] + r >= b[i + 1]) continue;
		++ans;
	}

	cout << ans << '\n';
	return 0;
}
