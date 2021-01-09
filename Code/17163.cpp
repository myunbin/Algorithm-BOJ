#include <bits/stdc++.h>
using namespace std;
const int MAX_M = 1e6 + 1;
int q, mod;
vector<int> s[MAX_M], tree;

void update(int node, int le, int ri, int idx) {
	if (ri < idx || idx < le) return;
	if (le == ri) {
		tree[node] = s[idx].back();
		return;
	}
	int mid = le + ri >> 1;
	update(node * 2, le, mid, idx);
	update(node * 2 + 1, mid + 1, ri, idx);
	tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

int query(int node, int le, int ri, int ql, int qr) {
	if (qr < le || ri < ql) return MAX_M;
	if (ql <= le && ri <= qr) return tree[node];
	int mid = le + ri >> 1;
	return min(query(node * 2, le, mid, ql, qr), query(node * 2 + 1, mid + 1, ri, ql, qr));
}

int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);

	cin >> q >> mod;
	
	if(mod >= MAX_M){
		while (q--) {
			int sel; cin >> sel;
			if(sel == 1) cin >> sel;
			else if(sel == 3) cout << -1 << '\n';
		}
		return 0;
	}
	
	tree.resize(4 * mod);
	fill(tree.begin(), tree.end(), -1);
	
	for (int i = 0; i < MAX_M; i++) s[i].push_back(-1);
	
	vector<int> v;
	while (q--) {
		int a; cin >> a;
		
		if (a == 1) {
			int n; cin >> n;
			n %= mod;
			s[n].push_back(v.size());
			v.push_back(n);
			update(1, 0, mod - 1, n);
		}
		else if (a == 2) {
			if (v.size() == 0) continue;
			s[v.back()].pop_back();
			update(1, 0, mod - 1, v.back());
			v.pop_back();
		}
		else {
			int ans = query(1, 0, mod - 1, 0, mod - 1);
			if (ans == -1) cout << ans << '\n';
			else cout << v.size() - ans << '\n';
		}
	}
	
	return 0;
}
