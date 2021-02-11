#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define ppb(x, y) push_back({x, y})
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 1e5 + 10;
const ll INF = 1e10;
struct tup{ ll ans, pmax, smax, asum; };
int n, m;
ll a[MAX_N];
tup t[4 * MAX_N];

tup merge(tup a, tup b) {
	tup ret;
	
	ret.ans = max({a.ans, b.ans, a.smax + b.pmax});
	ret.pmax = max(a.pmax, a.asum + b.pmax);
	ret.smax = max(b.smax, b.asum + a.smax);
	ret.asum = a.asum + b.asum;
	
	return ret;
}

void init(int nd, int le, int ri) {
	if (le == ri) {
		t[nd] = {a[le], a[le], a[le], a[le]};
		return;
	}
	
	int mid = le + ri >> 1;
	init(nd << 1, le, mid);
	init(nd << 1 | 1, mid + 1, ri);
	
	t[nd] = merge(t[nd << 1], t[nd << 1 | 1]);
}


tup query(int nd, int le, int ri, int ql, int qr) {
	if (ri < ql || qr < le) return {-INF, -INF, -INF, 0};
	if (ql <= le && ri <= qr) return t[nd];
	
	int mid = le + ri >> 1;
	auto lt = query(nd << 1, le, mid, ql, qr);
	auto rt = query(nd << 1 | 1, mid + 1, ri, ql, qr);
	
	return merge(lt, rt);
}

int main() {
	fio();	
	
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	
	init(1, 0, n - 1);
	
	cin >> m;
	while (m--) {
		int i, j;
		cin >> i >> j;
		i--, j--;
		cout << query(1, 0, n - 1, i, j).ans << '\n';
	}
	
	return 0;
}
