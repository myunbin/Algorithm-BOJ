#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);
	
    
	int n, k, b;
	cin >> n >> k >> b;
	
	vector<int> a(b);
	for (int i = 0; i < b; i++) cin >> a[i];
	sort(a.begin(), a.end());
	
	int s = 0, e = 0;
	while (e < b && a[e] <= k) e++;
	int ans = e;
	
	for (int s = 0; s < b; s++) {
		if (a[s] + k > n) break;
		while (e < b && a[e] - a[s] < k) e++;
		ans = min(ans, e - s - 1);
	}
	cout << ans << '\n';
	
    return 0;
}
