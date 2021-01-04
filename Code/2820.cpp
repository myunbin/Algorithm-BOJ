#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int MAX_N = 5e5 + 1;
int n, m;
vector<int> adj[MAX_N];
int w[MAX_N], cnt = 0;
bool visited[MAX_N];
pii child[MAX_N];
int table[MAX_N];
vector<int> tree, lazy;

int init(int node, int le, int ri) {
	if (le == ri) return tree[node] = w[table[le]];
	int mid = le + ri >> 1;
	return tree[node] = init(node * 2, le, mid) + init(node * 2 + 1, mid + 1, ri);
}

void propagate(int node, int le, int ri) {
	if (lazy[node] != 0) {
		tree[node] += (ri - le + 1) * lazy[node];
		if (le != ri) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}
int update(int node, int le, int ri, int ql, int qr, int d) {
	propagate(node, le, ri);
	
	if (ri < ql || qr < le) return tree[node];
	if (ql <= le && ri <= qr) {
		lazy[node] += d;
		propagate(node, le, ri);
		return tree[node];
	}
	int mid = le + ri >> 1;
	return tree[node] = update(node * 2, le, mid, ql, qr, d) 
		+ update(node * 2 + 1, mid + 1, ri, ql, qr, d);
}

int query(int node, int le, int ri, int ql, int qr) {
	propagate(node, le, ri);
	
	if (qr < le || ri < ql) return 0;
	if (ql <= le && ri <= qr) return tree[node];
	int mid = le + ri >> 1;
	return query(node * 2, le, mid, ql, qr) + query(node * 2 + 1, mid + 1, ri, ql, qr);
}

void dfs(int cur) {
	visited[cur] = true;
	child[cur].first = ++cnt;
	table[cnt] = cur;
	for (int nxt : adj[cur]) {
		if (!visited[nxt]) dfs(nxt);
	}
	child[cur].second = cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);
	
	cin >> n >> m;
	cin >> w[1];
	
	tree.resize(4 * n); lazy.resize(4 * n);
	
	for (int i = 2; i <= n; i++) {
		int x; cin >> w[i] >> x;
		adj[x].push_back(i);
	}

	dfs(1);
	init(1, 1, n);
	
	while (m--) {
		char c;
		int a, x;
		cin >> c >> a;
		
		int ql = child[a].first;
		int qr = child[a].second;
		
		if (c == 'p') {
			cin >> x;
			
			if (ql == qr) continue;
			update(1, 1, n, ql + 1, qr, x);
		}
		else cout << query(1, 1, n, ql, ql) << '\n';
	}
	return 0;
}
