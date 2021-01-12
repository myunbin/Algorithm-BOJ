#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
using namespace std;
typedef pair<int, int> pii;
const int MAX_N = 1010;
const int INF = 2e9;
struct e {int u, v, d;};
bool cmp(const e &a, const e &b) { return a.d < b.d; }

int p[MAX_N];
int f(int a) { 
	if (p[a] == a) return a;
	return p[a] = f(p[a]);	
}

bool merge(int a, int b) {
	a = f(a); b = f(b);
	if (a == b) return false;
	p[b] = a; return true;
}

int main() {
	fio();

	int n, m;
	cin >> n >> m;

	bool s[MAX_N];
	for (int i = 0; i < n; i++) {
		char c; cin >> c;
		s[i] = (c == 'M');
	}
	
	vector<e> edge;
	for (int i = 0; i < m; i++) {
		int u, v, d;
		cin >> u >> v >> d;
		edge.push_back({--u, --v, d});
	}
	sort(edge.begin(), edge.end(), cmp);

	for (int i = 0; i < n; i++) p[i] = i;

	int ans = 0, cnt = 0;
	for (int i = 0; i < m; i++) {
		int u = edge[i].u, v = edge[i].v, d = edge[i].d;
		if (s[u] != s[v] && merge(u, v)) {
			ans += d;
			++cnt;
		}
	}

	if (cnt != n - 1) cout << -1 << '\n';
	else cout << ans << '\n';

	return 0;
}
