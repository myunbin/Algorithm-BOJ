#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	
	int availMax = 0;
	
	for (int i = 0; i < n; i++) {
		if (availMax + 1 >= a[i]) 
			availMax += a[i];
		else break;
	}
	
	cout << availMax + 1 << '\n';
	
	return 0;
}
