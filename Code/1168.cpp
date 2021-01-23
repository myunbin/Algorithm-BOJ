#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define pb(x) push_back(x)
#define ppb(x, y) push_back({x, y})
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
vector<int> t;
int init(int node, int le, int ri) {
	if (le == ri) return t[node] = 1;
	int mid = le + ri >> 1;
	return t[node] = init(node * 2, le, mid) + init(node * 2 + 1, mid + 1, ri);
}

void update(int node, int le, int ri, int i, int v) {
	if (i < le || ri < i) return;
	if (le == ri) {
		t[node] += v;
		return;
	}
	int mid = le + ri >> 1;
	update(node * 2, le, mid, i, v);
	update(node * 2 + 1, mid + 1, ri, i, v);
	t[node] = t[node * 2] + t[node * 2 + 1];
}

int sum(int node, int le, int ri, int ql, int qr) {
	if (qr < le || ri < ql) return 0;
	if (ql <= le && ri <= qr) return t[node];
	int mid = le + ri >> 1;
	return sum(node * 2, le, mid, ql, qr) + sum(node * 2 + 1, mid + 1, ri, ql, qr);
} 

int find(int node, int le, int ri, int f) {
	if (le == ri) return le;
	int mid = le + ri >> 1;
	if (f > t[node * 2]) return find(node * 2 + 1, mid + 1, ri, f - t[node * 2]);
	return find(node * 2, le, mid, f);
}

int main() {
	fio();

	int n, k;
	cin >> n >> k;
	t.resize(4 * n);
	init(1, 1, n);

	int cur = k;
	cout << '<';
	for (int i = 0; i < n; i++) {
		cout << cur;
		if (i == n - 1) break;
		cout << ", ";
		update(1, 1, n, cur, -1);
		int s = sum(1, 1, n, cur, n);
		if (k <= s) cur = find(1, 1, n, t[1] - s + k);
		else {
			int m = (k - s) % t[1]; 
			if (m == 0) m = t[1];
			cur = find(1, 1, n, m);
		}
	}
	cout << '>';

	return 0;
}
