#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> a;
int n, m;

bool isPossible(int mid) {
	int sum = 0, cnt = 1;
	for (int i = 0; i < n; i++) {
		if (a[i] > mid) return false;
		sum += a[i];
		
		if (sum > mid) {
			sum = a[i];
			cnt++;
		}
	}
	
	return cnt <= m;
}
int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);

	cin >> n >> m;
	
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		a.push_back(x);
		sum += x;
	}	
	
	int le = 1, ri = sum + 1;
	int ans = 0;
	
	while (le <= ri) {
		int mid = le + ri >> 1;
		if (isPossible(mid)) {
			ans = mid;
			ri = mid - 1;
		}
		else le = mid + 1;
	}
	
	cout << ans << '\n';
	return 0;
}
