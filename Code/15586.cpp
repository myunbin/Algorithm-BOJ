#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define ppb(x, y) push_back({x, y})
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 1e5 + 10;
const int INF = 1e9 + 1;
struct e { 
	int u, v, w; 
	bool operator < (const e &o) {
		return w > o.w;
	}
};

struct qq {
	int k, u, idx;
	bool operator < (const qq &o) {
		return k > o.k;
	}
};

int p[MAX_N];

int find(int a) {
	if (p[a] < 0) return a;
	return p[a] = find(p[a]);
}

bool merge(int a, int b) {
	a = find(a), b = find(b);
	if (a == b) return false;
	p[a] += p[b];
	p[b] = a;
	return true;
}

int main() {
	fio();
	memset(p, -1, sizeof(p));

	int n, q;
	cin >> n >> q;

	vector<e> edge;
	for (int i = 0; i < n - 1; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edge.push_back({u, v, w});
	}

	sort(all(edge));

	
	vector<qq> query;
	for (int i = 0; i < q; i++) {
		int k, u;
		cin >> k >> u;
		query.push_back({k, u, i});
	}
	sort(all(query));
	
	int pos = 0;
	vector<int> ans(q);
	for (auto curq : query) {
		while (edge[pos].w >= curq.k) {
			merge(edge[pos].u, edge[pos].v);
			pos++;
		}
		ans[curq.idx] = -p[find(curq.u)];
	}
	
	for (int x : ans) cout << x - 1 << '\n';
	
	return 0;
}
