#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);
	
	int t;
	cin >> t;
	
	while (t--) {
		int n;
		cin >> n;
		
		int p[1010] = { 0 };
		
		for (int i = 1; i <= n; i++) {
			int x; cin >> x;
			p[i] = p[i - 1] + x;
		}
		
		int ans = -2e9;
		for (int s = 1; s <= n; s++) {
			for (int e = s; e <= n; e++) {
				ans = max(ans, p[e] - p[s - 1]);
			}
		}
		
		cout << ans << '\n';
	}
	return 0;
}
