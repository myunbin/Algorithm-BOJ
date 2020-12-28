#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 10;
const int INF = 2e9;
typedef long long ll;
typedef pair<int, int> pii;

int n;
vector<int> a;
vector<int> tree;

int init(int node, int le, int ri) {
	if (le == ri) return tree[node] = le;
	int mid = le + ri >> 1;
	int tmp1 = init(node * 2, le, mid);
	int tmp2 = init(node * 2 + 1, mid + 1, ri);
	
	if (a[tmp1] < a[tmp2]) return tree[node] = tmp1;
	else if (a[tmp1] == a[tmp2]) return tree[node] = min(tmp1, tmp2);
	else return tree[node] = tmp2;
}

int update(int node, int le, int ri, int i) {
	if (i < le || ri < i || le == ri) return tree[node];
	
	int mid = le + ri >> 1;
	int tmp1 = update(node * 2, le, mid, i);
	int tmp2 = update(node * 2 + 1, mid + 1, ri, i);
	
	if (a[tmp1] < a[tmp2]) return tree[node] = tmp1;
	else if (a[tmp1] == a[tmp2]) return tree[node] = min(tmp1, tmp2);
	else return tree[node] = tmp2;
}

int query(int node, int le, int ri, int ql, int qr) {
	if (qr < le || ri < ql) return -1;
	if (ql <= le && ri <= qr) return tree[node];
	
	int mid = le + ri >> 1;
	int tmp1 = query(node * 2, le, mid, ql, qr);
	int tmp2 = query(node * 2 + 1, mid + 1, ri, ql, qr);

	if (tmp1 == -1) return tmp2;
	if (tmp2 == -1) return tmp1;
	
	if (a[tmp1] < a[tmp2]) return tmp1;
	else if (a[tmp1] == a[tmp2]) return min(tmp1, tmp2);
	else return tmp2;
}
int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);

	cin >> n;
	a.resize(n + 1); tree.resize(4 * n);
	a[n] = INF;
	
	for (int i = 0; i < n; i++) cin >> a[i];
	init(1, 0, n - 1);
	
	int m; cin >> m;
	while (m--) {
		int x, y, z;
		cin >> x >> y >> z;
		
		if (x == 1) {
			a[y - 1] = z;
			update(1, 0, n - 1, y - 1);
		}
		else {
			cout << query(1, 0, n - 1, y - 1, z - 1) + 1 << '\n';
		}
	}
	
	return 0;
}
