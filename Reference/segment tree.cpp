#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> tree, a;

ll init(int node, int le, int ri) {
	if (le == ri) return tree[node] = a[le];
	int mid = le + ri >> 1;
	return tree[node] = init(node * 2, le, mid) + init(node * 2 + 1, mid + 1, ri);
}

ll update(int node, int le, int ri, int idx, int d) {
	if (ri < idx || idx < le) return tree[node];
	if (le == ri) return tree[node] = d;
	int mid = le + ri >> 1;
	return tree[node] = update(node * 2, le, mid, idx, d) + update(node * 2 + 1, mid + 1, ri, idx, d);
}

ll sum(int node, int le, int ri, int ql, int qr) {
	if (ri < ql || qr < le) return 0;
	if (ql <= le && ri <= qr) return tree[node];
	int mid = le + ri >> 1;
	return sum(node * 2, le, mid, ql, qr) + sum(node * 2 + 1, mid + 1, ri, ql, qr);
}

int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	a.resize(n);
	tree.resize(4 * n);
	
	for (int i = 0; i < n; i++) cin >> a[i];
	init(1, 0, n - 1);
	
	m += k;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) update(1, 0, n - 1, b - 1, c);
		else cout << sum(1, 0, n - 1, b - 1, c - 1) << '\n';
	}

	return 0;
}
