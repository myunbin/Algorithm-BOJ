#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k;
ll getCnt(ll x) {
	ll sum = 0;
	for (int i = 1; i <= n; i++) 
		sum += min(n, x / i);
	
	return sum;
}
int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);
	
	cin >> n >> k;
	
	ll le = 1, ri = n * n;
	ll ans = -1;
	while (le <= ri) {
		ll mid = (le + ri) >> 1;
		
		if (getCnt(mid) >= k) {
			ans = mid;
			ri = mid - 1;
		}
		else le = mid + 1;
	}
	
	cout << ans << '\n';
	
	return 0;
}
