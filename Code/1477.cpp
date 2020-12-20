#include <bits/stdc++.h>
using namespace std;

int n, m, l;
vector<int> h;

bool isPossible(int mid) {
	priority_queue<int> pq;
	pq.push(h[0] - 0);
	pq.push(l - h[n - 1]);
	
	for (int i = 0; i < n - 1; i++) 
		pq.push(h[i + 1] - h[i]);
	
	int cnt = 0;
	while (!pq.empty()) {
		int top = pq.top();
		pq.pop();
		if (top <= mid) break;
		
		cnt += top / mid - (top % mid == 0);
	}
	
	return (cnt <= m);
}
int main() {
	ios_base::sync_with_stdio(false);
  	cin.tie(nullptr);

	cin >> n >> m >> l;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		h.push_back(x);
	}
	sort(h.begin(), h.end());
	
	int le = 1, ri = l;
	int ans = -1;
	
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
