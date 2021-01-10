#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
using namespace std;
const int MAX_N = 1010;
struct e { int u, v, w; };
bool cmpA(const e &a, const e &b) {return a.w < b.w;}
bool cmpD(const e &a, const e &b) {return a.w > b.w;}

int p[MAX_N];
int find(int a) {
	if (a == p[a]) return a;
	return p[a] = find(p[a]);
}

bool merge(int a, int b) {
	a = find(a); b = find(b);
	if (a == b) return false;
	p[b] = a; return true;
}

int main() {
	fio();
	
	int n, m;
	cin >> n >> m;
	n++; m++;
	vector<e> edge;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edge.push_back({u, v, !w});
	}
	int x = 0, y = 0;
	
	sort(edge.begin(), edge.end(), cmpA);
	for (int i = 0; i < n; i++) p[i] = i;
	for (int i = 0; i < m; i++) if (merge(edge[i].u, edge[i].v)) x += edge[i].w;
	
	sort(edge.begin(), edge.end(), cmpD);
	for (int i = 0; i < n; i++) p[i] = i;
	for (int i = 0; i < m; i++) if (merge(edge[i].u, edge[i].v)) y += edge[i].w;
	
	cout << y * y - x * x << '\n';
	
	return 0;
}
