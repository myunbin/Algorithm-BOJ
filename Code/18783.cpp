#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 1e5 + 1;

int main() {
	fio();

	int n, m, k;
	cin >> n >> m >> k;
	vector<pii> a;
	for (int i = 0; i < m; i++) {
		int l, r; cin >> l >> r;
		a.push_back({l, r});
	}

	int b[MAX_N], p[MAX_N]; 
	for (int i = 1; i <= n; i++) p[i] = i;
	
	for (auto x : a) {
		int l = x.first, r = x.second;
		for (int i = l; i <= (l + r) >> 1; i++) swap(p[l + r - i], p[i]); 
	}

	int ans[MAX_N] = { 0 };

	for (int i = 1; i <= n; i++) {
		if (ans[i]) continue;
		int c = i; vector<int> cy;
		do {
			cy.pb(c);
			c = p[c];
		} while (i != c);

		int t = k % cy.size();
		for (int j = 0; j < cy.size(); j++) 
			ans[cy[j]] = cy[(j + t) % cy.size()];
	}

	for (int i = 1; i <= n; i++) cout << ans[i] << '\n';

	return 0;
}
