#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	vector<int> a(n);
	vector<int> b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	
	for (int x : b) 
		cout << lower_bound(a.begin(), a.end(), x) - a.begin() << ' ';
	
	return 0;
}
