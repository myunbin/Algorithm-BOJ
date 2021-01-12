#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
using namespace std;
typedef pair<int, int> pii;
const int MAX_N = 5e4 + 1;
int n, m;
int p[MAX_N];
vector<int> adj[MAX_N];

int f(int a) {
	if (p[a] == a) return a;
	return p[a] = f(p[a]);
}

void merge(int a, int b) {
	a = f(a); b = f(b);
	if (a == b) return;
	p[b] = a;
}

int main() {
	fio();
	for (int i = 0; i < MAX_N; i++) p[i] = i;
	cin >> n >> m;
	
	int ind[MAX_N] = { 0 };
	vector<pii> sp;
	
	while (m--) {
		int u, v; char c;
		cin >> u >> c >> v;
		u = f(u); v = f(v);
		if (c == '=') merge(u, v);
		else sp.push_back({u, v});
	}

	for (auto p : sp) {
		int u = f(p.first), v = f(p.second);
		adj[u].pb(v); ind[v]++;
	}

	queue<int> q;
	bool check[MAX_N] = { false };
	for (int i = 0; i < n; i++) {
		int x = f(i);
		if (!check[x] && !ind[x]) {
			q.push(x);
			check[x] = true;
		}
	}
	
	while (!q.empty()) {
		int c = f(q.front()); q.pop();
		for (int nxt : adj[c]) {
			if (!--ind[nxt]) q.push(nxt);
		}
	}

	for (int i = 0; i < n; i++) {
		if (!ind[i]) continue;
		cout << "inconsistent" << '\n';
		return 0;
	} 
	cout << "consistent" << '\n';

	return 0;
}
