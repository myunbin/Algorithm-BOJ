#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
using namespace std;
typedef vector<int> vi;
int n, m;
vector<vi> tree;
vi a;

vi init(int node, int le, int ri) {
	if (le == ri) {
		tree[node].pb(a[le]);
		return tree[node];
	}
	int mid = le + ri >> 1;
	vi t1 = init(node * 2, le, mid), t2 = init(node * 2 + 1, mid + 1, ri); 
	t1.insert(t1.end(), all(t2)); sort(all(t1));
	return tree[node] = t1;
}

int q(int node, int le, int ri, int ql, int qr, int k) {
	if (qr < le || ri < ql) return 0;
	if (ql <= le && ri <= qr) 
		return tree[node].end() - upper_bound(all(tree[node]), k);
	int mid = le + ri >> 1;
	return q(node * 2, le, mid, ql ,qr, k) + q(node * 2 + 1, mid + 1, ri, ql ,qr, k);
}


int main() {
	fio();
	cin >> n;
	a.resize(n); tree.resize(4 * n);
	for (int i = 0; i < n; i++) cin >> a[i];
	init(1, 0, n - 1);
	
	cin >> m;
	int last_ans = 0;
	while (m--) {
		int i, j, k;
		cin >> i >> j >> k;
		last_ans = q(1, 0, n - 1, i - 1, j - 1, k);
		cout << last_ans << '\n'; 
	}
	return 0;
}
