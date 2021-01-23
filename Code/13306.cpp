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
struct of{int x, a, b;};

vector<int> par;

int f(int a) {
	if (par[a] == a) return a;
	return par[a] = f(par[a]);
}
void m(int a, int b) {
	a = f(a), b = f(b);
	if (a == b) return;
	par[b] = a;
}
int main() {
	fio();

	int n, q;
	cin >> n >> q;
	
	vector<int> p(n + 1);
	par.resize(n + 1);
	for (int i = 1; i <= n; i++) par[i] = i;

	p[1] = 1;
	for (int i = 2; i <= n; i++) {
		int x; cin >> x;
		p[i] = x;
	}

	q += n - 1;
	vector<of> query(q);
	for (int i = 0; i < q; i++) {
		cin >> query[i].x;
		if (query[i].x) cin >> query[i].a >> query[i].b;
		else cin >> query[i].a;
	}
	reverse(all(query));

	vector<bool> ans;
	for (int i = 0; i < q; i++) {
		if (query[i].x) ans.pb(f(query[i].a) == f(query[i].b));
		else m(query[i].a, p[query[i].a]);
	}
	reverse(all(ans));
	
	for (bool b : ans) {
		if (b) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	
	return 0;
}
