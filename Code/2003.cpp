#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 1;
typedef long long ll;
typedef pair<int, char> pic;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);
	
	int n;
	ll m;
	cin >> n >> m;
	
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	
	int s = 0, e = 0;
	ll sum = 0, ans = 0;
	while (s <= e) {
		if (sum >= m) sum -= a[s++];
		else if (e == n) break;
		else sum += a[e++];
		if (sum == m) ans++;
	}
	
	cout << ans << '\n';
	return 0;
}
