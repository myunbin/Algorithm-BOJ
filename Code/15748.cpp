#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);
	
	int l, n, rf, rb;
	cin >> l >> n >> rf >> rb;
	vector<P> a;
	for (int i = 0; i < n; i++) {
		int x, c;
		cin >> x >> c;
		a.push_back({c, x});
	}
	sort(a.begin(), a.end(), greater<>());
	
	ll ans = 0;
	int lastPos = 0;
	
	for (int i = 0; i < n; i++) {
		int x = a[i].second;
		int c = a[i].first;
		
		if (x <= lastPos) continue;	
		ans += (ll)(rf - rb) * c * (x - lastPos);
		lastPos = x;
	}
	
	cout << ans << '\n';
	
	return 0;
}
