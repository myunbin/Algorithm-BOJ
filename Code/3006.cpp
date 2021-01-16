#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define ppb(x, y) push_back({x, y})
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 1e5 + 1;
int n;
vector<int> t, p;
void update(int i, int v) {
	for (; i <= n; i += (i & -i)) t[i] += v;
}
int query(int i, int s = 0) {
	for (; i >= 1; i -= (i & -i)) s += t[i];
	return s;
}

int main() {
	fio();
	cin >> n;
	t.resize(n + 1, 0), p.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		update(x, 1);
		p[x] = i;
	}

	for (int i = 1; i <= (n + 1) / 2; i++) {
		int s = i, e = n - i + 1;
		
		int ps = p[s], pe = p[e];
		cout << query(ps - 1) << '\n';
		update(ps, -1);

		if (s == e) break;
		cout << query(n) - query(pe) << '\n';
		update(pe, -1);
	}

	return 0;
}
