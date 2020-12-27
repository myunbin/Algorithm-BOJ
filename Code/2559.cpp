#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 1;
typedef pair<int, int> pii;
 
int a[MAX_N], pSum[MAX_N];
int n, k;

int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pSum[i] = pSum[i - 1] + a[i];
	} 
	
	int ans = -2e9;
	for (int i = 1; i + k - 1 <= n; i++) 
		ans = max(ans, pSum[i + k - 1] - pSum[i - 1]);
	
	cout << ans << '\n';
	return 0;
}
