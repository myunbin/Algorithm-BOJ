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
struct q1 {int x, i, v;};
struct q2 {
	int x, k, i, j, idx;
	bool operator < (q2 const &o) {
		return k < o.k;
	}
};

int n, m;
vector<ll> t;

void update(int node, int le, int ri, int i, int v) {
	if (i < le || ri < i) return;
	if (le == ri) {
		t[node] = v;
		return;
	}
	int mid = le + ri >> 1;
	update(node * 2, le, mid, i, v);
	update(node * 2 + 1, mid + 1, ri, i, v);
	t[node] = t[node * 2] + t[node * 2 + 1];
}

ll query(int node, int le, int ri, int ql, int qr) {
	if (qr < le || ri < ql) return 0;
	if (ql <= le && ri <= qr) return t[node];
	int mid = le + ri >> 1;
	return query(node * 2, le, mid, ql, qr) + query(node * 2 + 1, mid + 1, ri, ql, qr);
} 

int main() {
	fio();

	cin >> n;
	t.resize(4 * n, 0);
	for (int i = 1; i <= n; i++) {
		ll x; cin >> x;
		update(1, 1, n, i, x);
	}

	//cout << query(4) - query(0) << '\n';
	
	vector<q1> qu1;
	vector<q2> qu2;
	
	cin >> m;
	int p = 0;
	for (int i = 0; i < m; i++) {
		int x, a, b, c; 
		cin >> x;
		if (x == 1) {
			cin >> a >> b;
			qu1.push_back({x, a, b});
		}
		else {
			cin >> a >> b >> c;
			qu2.push_back({x, a, b, c, p++});
		}
	}

	sort(all(qu2));

	int curk = 1;
	vector<ll> ans(qu2.size());

	for (auto q : qu2) {
		//cout << q.k << ' ' << q.idx << '\n';
		while (curk <= q.k) {
			update(1, 1, n, qu1[curk - 1].i, qu1[curk - 1].v);
			++curk;
		}
		ans[q.idx] = query(1, 1, n, q.i, q.j);
		//cout << "curk : " << curk << "  ans : " << ans[q.idx] << '\n';
	}

	for (ll res : ans) cout << res << '\n';

	return 0;
}
