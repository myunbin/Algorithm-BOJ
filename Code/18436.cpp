#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
using namespace std;
int n, m;
vector<int> a, t;

int init(int node, int le, int ri) {
	if (le == ri) return t[node] = a[le] % 2;
	int mid = le + ri >> 1;
	return t[node] = init(node * 2, le, mid) + init(node * 2 + 1, mid + 1, ri);
}

void update(int node, int le, int ri, int i, int d) {
	if (i < le || ri < i) return;
	if (le == ri) {
		t[node] = d % 2;		
		return;
	} 
	int mid = le + ri >> 1;
	update(node * 2, le, mid, i, d);
	update(node * 2 + 1, mid + 1, ri, i, d);
	t[node] = t[node * 2] + t[node * 2 + 1];
}

int query(int node, int le, int ri, int ql, int qr) {
	if (qr < le || ri < ql) return 0;
	if (ql <= le && ri <= qr) return t[node];
	int mid = le + ri >> 1;
	return query(node * 2, le, mid, ql, qr) + query(node * 2 + 1, mid + 1, ri, ql, qr);
}

int main() {
	fio();
	
	cin >> n;
	a.resize(n); t.resize(4 * n);
	for (int i = 0; i < n; i++) cin >> a[i];
	init(1, 0, n - 1);
	
	cin >> m;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) update(1, 0, n - 1, b - 1, c);
		else if (a == 2) cout << (c - b + 1) - query(1, 0, n - 1, b - 1, c - 1) << '\n';
		else cout << query(1, 0, n - 1, b - 1, c - 1) << '\n';
	}
	
	return 0;
}
