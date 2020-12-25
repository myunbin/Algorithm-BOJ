#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	vector<pii> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	
	sort(a.begin(), a.end());
	
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(a[0].second);
	
	int ans = 1;
	
	for (int i = 1; i < n; i++) {
		int s = a[i].first;
		int e = a[i].second;
		
		int top = pq.top();
		if (top <= s) pq.pop();
		else ans++;
		
		pq.push(e);
	}
	
	cout << ans << '\n';
	
	return 0;
}
