#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define pb(x) push_back(x)
#define ppb(x, y) push_back({x, y})
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 2e5 + 10;
const int INF = 1e9;
int n, d[MAX_N] = { 0 };
vector<pii> a;
vector<int> b;

int idx(int x) {
	return lower_bound(all(b), x) - b.begin();
}

int main() {
	fio();

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		a.ppb(s, e), b.pb(s), b.pb(e);
	}

	sort(all(b));
	b.erase(unique(all(b)), b.end());

	for (int i = 0; i < n; i++) {
		int s = idx(a[i].first), e = idx(a[i].second);
		d[s]++, d[e]--;
	}

	int sum = 0;
	for (int i = 1; i < MAX_N; i++) d[i] += d[i - 1];
	for (int i = 0; i < MAX_N - 1; i++) {
		if (d[i] > 0) sum += b[i + 1] - b[i];
	}

	int d1[MAX_N] = { 0 };
	d1[0] = (d[0] == 1 ? b[1] - b[0] : 0);
	for (int i = 1; i < MAX_N; i++) {
		int c = 0;
		if (d[i] == 1) c = b[i + 1] - b[i];
		d1[i] = d1[i - 1] + c;
	}

	int i = 0, out = 0, ans = 0;

	for (int i = 0; i < n; i++) {
		int s = idx(a[i].first), e = idx(a[i].second);
		int le, ri;
		if (s == 0) le = 0;
		else le = d1[s - 1];
		ri = d1[e - 1];
		ans = max(ans, sum - (ri - le));
	}
	
	cout << ans << '\n';
	return 0;
}
