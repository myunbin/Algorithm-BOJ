#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a;

bool isPossible(int mid) {
	int s = 0, e = 0;
	int cnt = 1;
	vector<int> temp;
	
	while (e < n) {
		temp.resize(e - s + 1);
		copy(a.begin() + s, a.begin() + e + 1, temp.begin());
		
		int minT = 1e5 + 1, maxT = -1;
		for (int x : temp) {
			minT = min(minT, x);
			maxT = max(maxT, x);
		}
		int score = maxT - minT;
		
		if (score > mid) {
			s = e;
			cnt++;
		} 
		else e++;
	}
	
	return (cnt <= m);
}
int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);

	cin >> n >> m;
	a.resize(n);
	int maxA = -1;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		maxA = max(maxA, a[i]);
	}	

	int le = 0, ri = maxA;
	int ans = maxA + 1;
	
	while (le <= ri) {
		int mid = le + ri >> 1;
		if (isPossible(mid)) {
			ans = min(ans, mid);
			ri = mid - 1;
		}
		else le = mid + 1;
	}
	
	cout << ans << '\n';
	return 0;
}
