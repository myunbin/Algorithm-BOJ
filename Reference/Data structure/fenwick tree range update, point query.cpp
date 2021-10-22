#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define ppb(x, y) push_back({x, y})
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tp;
const int MAX_N = 1e5 + 10;
const int INF = 2e9;
int n;
vector<ll> tr(MAX_N);

void update(int i, int v) {
	for (; i < MAX_N; i += (i & -i)) tr[i] += v;
}
void update(int l, int r, int v) {
	update(l, v), update(r + 1, -v);
}
ll query(int i, ll s = 0) {
	for (; i > 0; i -= (i & -i)) s += tr[i];
	return s;
}

int main() {
	fio();

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int s, e; cin >> s >> e;
		ll a = query(s), b = query(e);

		cout << a + b << '\n';
		update(s, s, -a), update(e, e, -b);
		update(s + 1, e - 1, 1);
	}

	return 0;
}
