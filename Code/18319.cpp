#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define ppb(x, y) push_back({x, y})
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tp;
const int MAX_N = 1e6 + 1;
const int INF = 2e9;

int main() {
	fio();
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	int m = -1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		m = max(m, a[i]);
	}

	int ans = 0;
	for (int i = 1; i <= m; i++) {
		int s = 0;
		vector<int> mod(n);
		for (int j = 0; j < n; j++) {
			s += a[j] / i;
			mod[j] = a[j] % i;
		}
		if (s < k / 2) break;
		if (s >= k) {
			ans = max(ans, i * k / 2);
			continue;
		}
		sort(all(mod), greater<int>());
		int t = i * (s - k / 2);
		for (int i = 0; i < n && s + i < k; i++) 
			t += mod[i];
		ans = max(ans, t);
	}

	cout << ans << '\n';
	return 0;
}
