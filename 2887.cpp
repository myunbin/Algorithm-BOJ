#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 100010;
typedef long long ll;

struct V { int idx, x, y, z; };
struct E {
	int u, v, w;
	bool operator < (const E& other) const { return w < other.w; }
};

bool cmpX(V a, V b) { return a.x < b.x; }
bool cmpY(V a, V b) { return a.y < b.y; }
bool cmpZ(V a, V b) { return a.z < b.z; }

int uf[MAX_V];

int find(int a) {
	if (uf[a] < 0) return a;
	return uf[a] = find(uf[a]);
}

bool merge(int a, int b) {
	a = find(a); b = find(b);
	if (a == b) return false;
	uf[a] = b;
	return true;
}

void solve() {
	int N;
	cin >> N;
	
	vector<V> planet;
	vector<E> edge;
	
	for (int i = 1; i <= N; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		
		planet.push_back({i, x, y, z});
	}
	
	sort(planet.begin(), planet.end(), cmpX);
	for (int i = 0; i < N - 1; i++) 
		edge.push_back({planet[i].idx, planet[i + 1].idx, abs(planet[i + 1].x - planet[i].x)});

	sort(planet.begin(), planet.end(), cmpY);
	for (int i = 0; i < N - 1; i++) 
		edge.push_back({planet[i].idx, planet[i + 1].idx, abs(planet[i + 1].y - planet[i].y)});

	sort(planet.begin(), planet.end(), cmpZ);
	for (int i = 0; i < N - 1; i++) 
		edge.push_back({planet[i].idx, planet[i + 1].idx, abs(planet[i + 1].z - planet[i].z)});

	sort(edge.begin(), edge.end());
	
	fill(uf, uf + MAX_V, -1);
	ll ans = 0;
	int cnt = 0;
	
	for (int i = 0;; i++) {
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
