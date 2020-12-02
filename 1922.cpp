#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 1010;
const int MAX_E = 100010;
int uf[MAX_V];

int find(int a) {
	if (uf[a] < 0) return a;
	return uf[a] = find(uf[a]);
}

bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	
	if (a == b) return false;
	uf[b] = a;
	return true;
}

struct E {
	int u, v, w;
	E(): E(-1, -1, 0){}
	E(int a, int b, int c) : u(a), v(b), w(c) {}
	bool operator < (const E& other) const { return w < other.w; }
};

void solve() {
	int N, M;
	cin >> N >> M;
	
	vector<E> edge;
	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		
		edge.push_back({u, v, w});
	}
	sort(edge.begin(), edge.end());
	
	int ans = 0, cnt = 0;
	fill(uf, uf + MAX_V, -1);
	
	for (int i = 0; i < M; i++) {
		int curU = edge[i].u;
		int curV = edge[i].v;
		int curW = edge[i].w;
		
		if (merge(curU, curV)) {
			ans += curW;
			if (++cnt == N - 1) break;
		}
	}
	
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	return 0;
}
