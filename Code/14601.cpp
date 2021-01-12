#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
using namespace std;
const int MAX_K = 7;
int cnt, a[1 << MAX_K | 1][1 << MAX_K | 1];

bool chk(int s, int x, int y) {
	for (int i = x; i < x + s; i++) {
		for (int j = y; j < y + s; j++) {
			if (a[i][j] != 0) return false;
		}
	}
	return true;
}

void solve(int s, int x, int y) {
	if (s == 1) return;
	++cnt;
	int ns = s >> 1;
	if (chk(ns, x, y)) a[x + ns - 1][y + ns - 1] = cnt;
	if (chk(ns, x, y + ns)) a[x + ns - 1][y + ns] = cnt; 
	if (chk(ns, x + ns, y)) a[x + ns][y + ns - 1] = cnt; 
	if (chk(ns, x + ns, y + ns)) a[x + ns][y + ns] = cnt; 

	solve(ns, x, y); solve(ns, x + ns, y); solve(ns, x, y + ns); solve(ns, x + ns, y + ns);
}

int main() {
	fio();

	int n; cin >> n;
	int x, y; cin >> x >> y; 
	a[--y][--x] = -1;

	solve(1 << n, 0, 0);
	
	for (int i = (1 << n) - 1; i >= 0; i--) {
		for (int j = 0; j < (1 << n); j++) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}
