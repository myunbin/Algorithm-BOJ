#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define ppb(x, y) push_back({x, y})
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
vector<ll> a, b, t;
int n;
void update(int i, int v) {
	for (; i <= n; i += (i & -i)) t[i] += v;
}
int query(int i, ll s = 0) {
	for (; i >= 1; i -= (i & -i)) s += t[i];
	return s; 
}
int main() {
	fio();

	cin >> n;
	a.resize(n + 1), b.resize(n + 1), t.resize(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(all(a));
	a.erase(unique(all(a)), a.end());
	
	for (int i = 1; i <= n; i++) {
		int x = lower_bound(all(a), b[i]) - a.begin();
		cout << i - query(x - 1) << '\n';
		update(x, 1);
	}

	return 0;
}
