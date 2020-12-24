#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int k, n;

int solve(int x) {
	int t = 0;
	int l = 0, r = 0;
	
	for (int v = 1;; v++) {
		t++;
		l += v;
		
		if (l + r >= k) return t;
		if (v >= x) {
			r += v;
			t++;
			if (l + r >= k) return t;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);
	
	cin >> k >> n;
	
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		
		cout << solve(x) << '\n';
	}
	
	return 0;
}
