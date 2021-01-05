#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<int> a(m);
	for (int i = 0; i < m; i++) cin >> a[i];	
	sort(a.begin(), a.end());
	
	vector<bool> check(m, false);
	for (int i = 0; i < k; i++) {
		int x; cin >> x;
		int pos = upper_bound(a.begin(), a.end(), x) - a.begin();
		
		while (check[pos]) pos++;
		check[pos] = true;
		
		cout << a[pos] << '\n';
	}
	return 0;
}
