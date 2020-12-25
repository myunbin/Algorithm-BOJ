#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	
	int minD = 2e9;
	P ans;

	int le = 0, ri = n - 1;
	while (le < ri) {
		int d = a[le] + a[ri];
		if (minD > abs(d)) {
			minD = abs(d);
			ans.first = a[le];
			ans.second = a[ri];
		}
		
		if (d < 0) le++;
		else if (d > 0) ri--;
		else break;
	}
	
	cout << ans.first << ' ' << ans.second << '\n';
	return 0;
}
