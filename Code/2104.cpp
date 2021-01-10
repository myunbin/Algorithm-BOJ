#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
using namespace std;
typedef long long ll;
const int MAX_N = 1e5 + 1;
int n;
ll a[MAX_N];

ll go(int le, int ri) {
	if (le == ri) return a[le] * a[le];
	
	int mid = le + ri >> 1;
	ll ret = max(go(le, mid), go(mid + 1, ri));
	
	int lo = mid, hi = mid + 1;
	ll s = a[lo] + a[hi], m = min(a[lo], a[hi]);
	
	while (le <= lo && hi <= ri) {
		if (lo == le || a[lo - 1] < a[hi + 1]) {
			hi++;
			s += a[hi];
			m = min(m, a[hi]);
		}
		else {
			lo--;
			s += a[lo];
			m = min(m, a[lo]);
		}
		ret = max(ret, s * m);
	} 
	return ret;
}
int main() {
	fio();
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	
	cout << go(0, n - 1) << '\n';
	
	return 0;
}
