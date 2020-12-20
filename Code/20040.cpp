#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
const int MAX_N = 5e5 + 1;
int p[MAX_N];

int find(int a) {
	if (p[a] < 0) return a;
	return p[a] = find(p[a]);
}

bool merge(int a, int b) {
	a = find(a); b = find(b);
	if (a == b) return false;
	p[a] = b;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);
	
	memset(p, -1, sizeof(p));
	
	int n, m;
	cin >> n >> m;
	
	int ans = n + 1;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		
		if (!merge(u, v)) {
			ans = min(ans, i + 1);
		}
	}
	
	if (ans == n + 1) cout << 0 << '\n';
	else cout << ans << '\n';
	
	return 0;
}
