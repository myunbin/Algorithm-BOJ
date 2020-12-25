#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);
	
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.begin(), a.end());
	
	
	vector<pair<int, int>> ans(n);
	
	int cnt = 0;
	
	for (int i = 0; i < n; i++) {
		ans[i].first = a[i].second;
		ans[i].second = cnt;
		if (i != n - 1 && a[i].first != a[i + 1].first) cnt++;
	}
	sort(ans.begin(), ans.end());
	
	for (auto x : ans) cout << x.second << ' ';
	
	return 0;
}
