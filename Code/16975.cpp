#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
using namespace std;
typedef long long ll;
vector<ll> tree, lazy, a;

ll init(int node, int le, int ri) {
	if (le == ri) return tree[node] = a[le];
	int mid = le + ri >> 1;
	return tree[node] = init(node * 2, le, mid) + init(node * 2 + 1, mid + 1, ri);
}

void propagate(int node, int le, int ri) {
	if (lazy[node] != 0) {
		tree[node] += lazy[node] * (ri - le + 1);
		if (le != ri) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int node, int le, int ri, int ql, int qr, int d) {
	propagate(node, le, ri);
	if (qr < le || ri < ql) return;
	if (ql <= le && ri <= qr) {
		lazy[node] += d;
		propagate(node, le, ri);
		return;
	}
	int mid = le + ri >> 1;
	update(node * 2, le, mid, ql, qr, d);
	update(node * 2 + 1, mid + 1, ri, ql, qr, d);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(int node, int le, int ri, int ql, int qr) {
	propagate(node, le, ri);
	if (qr < le || ri < ql) return 0;
	if (ql <= le && ri <= qr) return tree[node];
	int mid = le + ri >> 1;
	return query(node * 2, le, mid, ql, qr) + query(node * 2 + 1, mid + 1, ri, ql, qr);
}

int main() {
	fio();

	int n, m;
	cin >> n;
	a.resize(n); tree.resize(4 * n); lazy.resize(4 * n);
	for (int i = 0; i < n; i++) cin >> a[i];
	init(1, 0, n - 1);
	cin >> m;
	while (m--) {
		int a, b, c, k;
		cin >> a >> b;
		if (a == 1) {
			cin >> c >> k;
			b--; c--;
			update(1, 0, n - 1, b, c, k);
		}
		else cout << query(1, 0, n - 1, b - 1, b - 1) << '\n';
	}
	
	return 0;
}
