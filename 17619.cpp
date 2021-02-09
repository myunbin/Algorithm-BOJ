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
vector<tp> a;

int p[MAX_N];

int find(int a) {
	if (a == p[a]) return a;
	return p[a] = find(p[a]);
}

void merge(int a, int b) {
	a = find(a), b = find(b);
	if (a == b) return;
	p[b] = a;
}

int main() {
	fio();
	for (int i = 0; i < MAX_N; i++) p[i] = i;
	int n, q;
	cin >> n >> q;
	
	for (int i = 1; i <= n; i++) {
		int x1, x2, y;
		cin >> x1 >> x2 >> y;
		a.push_back({x1, x2, i});
	}
	sort(all(a));

	int ri = get<1>(a[0]);

	for (int i = 1; i < n; i++) {
		auto [f, s, idx] = a[i];
		if (f <= ri) merge(idx, get<2>(a[i - 1]));
		ri = max(ri, s);
	}

	for (int i = 0; i < q; i++) {
		int u, v; cin >> u >> v;
		cout << (int)(find(u) == find(v)) << '\n';
	}

	return 0;
}
