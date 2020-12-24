#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 3e5 + 1;
typedef pair<int, int> P;

int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	vector<P> a;
	
	for (int i = 0; i < n; i++) {
		int d, x;
		cin >> d >> x;
		a.push_back({d, x});
	}
	sort(a.begin(), a.end());
	
	int l, p;
	cin >> l >> p;
	
	priority_queue<P> pq;
	
	int cur = 0, fuel = p, idx = 0;
	int ans = 0;
	
	while (true) {
		if (cur + fuel >= l) {
			cur += fuel;
			break;
		}
		
		while (idx < n && cur + fuel >= a[idx].first) {
			pq.push({a[idx].second, idx});
			idx++;
		}
		
		if (pq.empty()) break;
		
		int nxt = a[pq.top().second].first;
		fuel -= (nxt - cur);
		fuel += pq.top().first;
		cur = nxt;
		
		ans++;
		pq.pop();
		
	}
	
	if (cur < l) cout << -1;
	else cout << ans;
	
	return 0;
}
